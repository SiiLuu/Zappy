/*
** EPITECH PROJECT, 2020
** client.cpp
** File description:
** client.cpp
*/

#include "client.hpp"

bool running = true;

client::client()
{
}

client::~client()
{
}

int client::find_coord(int x_y)
{
    std::string str;
    int space = x_y == 0 ? 4 : 6;
    int res = 0;
    std::stringstream geek;

    for (auto i = this->queue.begin(); i != this->queue.end(); ++i)
        if (!i->find("msz") && (x_y == 0 || x_y == 1)) {
            str = *i;
            str.erase(str.begin(), str.begin() + space);
            geek = std::stringstream(str);
            geek >> res;
            return (res);
        }
    return (-1);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

void client::initialize_graphical(int client_socket)
{
    dprintf(client_socket, "mct\n");
    delay(1);
    dprintf(client_socket, "tna\n");
}

void client::which_command(std::string str)
{
    if (!str.find("pnw"))
        this->nb_player_connected++;
    if (!str.find("disconnect")) {
        dprintf(1, "You have been disconnected from the server\n");
        running = false;
    }
    if (!str.find("Wrong team name")) {
        dprintf(1, "Team name is not recognised\n");
        running = false;
    }
    if (!str.find("Not enough slots")) {
        dprintf(1, "Not enough slots in this team\n");
        running = false;
    }
}

void client::graphicalLoop(int client_socket)
{
    fd_set fdr;
    fd_set fdw;
    int fd_type = READ;
    std::string events;
    std::string temp2;
    char *temp = NULL;
    std::unique_ptr<Sfml> _sfml;

    while (running) {
        connection(client_socket, &fd_type, &fdr, &fdw);
        checkRead(fdr, fd_type, client_socket);
        if (!_sfml) {
            if (find_coord(0) != -1) {
                _sfml = std::unique_ptr<Sfml>(new Sfml(find_coord(0), find_coord(1)));
                initialize_graphical(client_socket);
                dprintf(client_socket, "teamName: %s\n", this->teamName.c_str());
            } else
                continue;
        }
        events = _sfml->registerEvents();
        if (!events.compare("CLOSE"))
            break;
        for (auto i = this->queue.begin(); i != this->queue.end(); ++i) {
            std::cout << *i << std::endl;
            _sfml->display(*i);
            which_command(*i);
        }
        this->queue.clear();
    }
    close(client_socket);
}
