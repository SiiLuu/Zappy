/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** trantorian
*/

#include <string>
#include "trantorian.hpp"

bool iaRunning = true;

trantorian::trantorian(int level) : elevation(), client(), Path(), commandHandler(),
    _food(Inventory::Food()), _stones(Inventory::Stones()), _level(level)
{
    initItemTypesVector();
}

void signal_handler(int signal)
{
    (void)signal;
    std::cout << std::endl;
}

void trantorian::initItemTypesVector()
{
    this->itemTypes.push_back("food");
    this->itemTypes.push_back("linemate");
    this->itemTypes.push_back("deraumere");
    this->itemTypes.push_back("sibur");
    this->itemTypes.push_back("mendiane");
    this->itemTypes.push_back("phiras");
    this->itemTypes.push_back("thystame");
}

void trantorian::parseItem(std::string item)
{
    //DEBUG look for any number in item (not the best method)
    if (item.find_first_of("0123456789") == std::string::npos) {
        return ;
    }
    std::string item_type = item.substr(0, item.find(' '));
    int nb = std::stoi(item.substr(item.find(' '), item.length()));
    int resType = 0;

    for (std::vector<std::string>::iterator it = this->itemTypes.begin();
        it != this->itemTypes.end(); ++it, resType++) {
        if (it->compare(item_type) == 0)
            break;
    }
    switch(resType) {
        case 0:
            this->_food.setUnits(nb);
            break;
        case 1:
            this->_stones.setLinemate(nb);
            break;
        case 2:
            this->_stones.setDeraumere(nb);
            break;
        case 3:
            this->_stones.setSibur(nb);
            break;
        case 4:
            this->_stones.setMendiane(nb);
            break;
        case 5:
            this->_stones.setPhiras(nb);
            break;
        case 6:
            this->_stones.setThystame(nb);
            break;
        default:
            break;
    }
}

void trantorian::fillInventory(std::vector<std::string> inventory)
{
    for (std::vector<std::string>::iterator it = inventory.begin();
        it != inventory.end(); ++it) {
        if (check_cmd(std::string(it->data())) == -1 && !std::string(it->data()).compare(0, 2, "KO"))
            break;
        parseItem(std::string(it->data()));
    }
}

bool trantorian::checkElevation(void)
{
    if (_food.getStatus() != _food.CRITICAL && getLinemate(_level) <= _stones.getLinemate()
        && getDeraumere(_level) <= _stones.getDeraumere() && getSibur(_level) <= _stones.getSibur()
        && getMendiane(_level) <= _stones.getMendiane() && getPhiras(_level) <= _stones.getPhiras()
        && getThystame(_level) <= _stones.getThystame()) {
        if (!cmd_Incantation().compare(0, 2, "KO"))
            return true;
        _level++;
        return false;
    }
    return false;
}

int trantorian::move_to_resource(std::string resource, std::vector<std::string> vision)
{
    std::vector<int> list_cmd = find_path(vision, resource);
    int result = 0;

    for (size_t index = 0; index < list_cmd.size();) {
        if (list_cmd.at(index) == Forward)
            result = check_cmd(cmd_Forward());
        else if (list_cmd.at(index) == Right)
            result = check_cmd(cmd_Right());
        else if (list_cmd.at(index) == Left)
            result = check_cmd(cmd_Left());
        else if (list_cmd.at(index) == Take)
            result = check_cmd(cmd_Take_obj(resource));
        if (result == 0)
            index++;
        else if (result == 1)
            return DEAD;
    }
    return 0;
}

int trantorian::check_cmd(std::string cmd_result)
{
    std::vector<std::string> cmd_vector;
    std::string direction;

    if (cmd_result.compare(0, 4, "DEAD") == 0)
        return DEAD;
    if (cmd_result.compare(0, 2, "OK") == 0)
        return 0;
    if (cmd_result.compare(0, 2, "KO") == 0)
        return 1;
    if (cmd_result.compare(0, 17, "start_incantation") == 0) {
        cmd_vector = this->strToWordVector(cmd_result);
        if (!cmd_vector.empty() && (stoi(cmd_vector[1]) != _level || _food.getStatus() == _food.CRITICAL))
            return 1;
        if (cmd_vector[2].compare(0, 4, "Left") == 0)
            check_cmd(client::cmd_Left());
        else if (cmd_vector[2].compare(0, 5, "Right") == 0)
            check_cmd(client::cmd_Left());
        else if (cmd_vector[2].compare(0, 7, "Forward") == 0)
            check_cmd(client::cmd_Left());
        return 0;
    }
    return 1;
}

void trantorian::iaLoop(int client_socket)
{
    int fd_type = READ;
    bool first = false;

    std::signal(SIGINT, signal_handler);
    while (iaRunning) {
        connection(client_socket, &fd_type, &this->fdr, &this->fdw);
        checkRead(this->fdr, fd_type, client_socket);
        if (!first) {
            dprintf(client_socket, "teamName: %s\n", this->teamName.c_str());
            first = !first;
        }
        for (auto i = this->queue.begin(); i != this->queue.end(); i++) {
            std::cout << *i << std::endl;
            which_command(*i);
        }
        if (iaRunning)
            this->state_machine();
        this->queue.clear();
    }
    close(client_socket);
}

void trantorian::which_command(std::string str)
{
    if (!str.find("pnw"))
        nb_player_connected++;
    if (!str.find("disconnect")) {
        dprintf(1, "You have been disconnected from the server\n");
        iaRunning = false;
    }
    if (!str.find("Wrong team name")) {
        dprintf(1, "Team name is not recognised\n");
        iaRunning = false;
    }
    if (!str.find("Not enough slots")) {
        dprintf(1, "Not enough slots in this team\n");
        iaRunning = false;
    }
}

int trantorian::check_fork(void)
{
    std::string result = cmd_Connect();

    if (check_cmd(result) == DEAD)
        return (DEAD);
    return check_cmd(cmd_Fork());
}

int trantorian::state_machine(void)
{
    std::vector<std::string> vision = cmd_Look();
    if (!vision.empty() && check_cmd((vision.at(0))) == DEAD)
        return DEAD;
    fillInventory(this->cmd_Inventory());
    bool elevation = checkElevation();
    std::string priority = compareLevelPriority(_level, vision, _stones, _food);
    // DEBUG PRINT
    std::cerr << "level:" << _level  << " priority: " << priority << std::endl;

    if (priority.compare("none")) {
        if (move_to_resource(priority, vision) == DEAD)
            return DEAD;
    } else if (elevation) {
        if (check_cmd(cmd_Broadcast(std::string("start_incantation ")
            + std::to_string(_level))) == DEAD)
            return DEAD;
        if (check_fork() == DEAD)
            return DEAD;
    } else if (check_cmd(cmd_Forward()) == DEAD)
            return DEAD;
    return 0;
}

int trantorian::clientLoop(int client_socket)
{
    (this->teamName.compare("GRAPHIC") == 0) ? graphicalLoop(client_socket) : iaLoop(client_socket);
    return (0);
}
