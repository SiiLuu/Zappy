/*
** EPITECH PROJECT, 2020
** command
** File description:
** Zappy
*/

#include "client.hpp"

std::string client::server_answer(int client_socket, const char *command)
{
    char buffer[MAX_BUFFER];

    if (send(client_socket, command, MAX_BUFFER, MSG_NOSIGNAL) == -1) {
        which_command("disconnect");
        exit(0);
    }
    bzero(buffer, sizeof(buffer));
    if (read(client_socket, buffer, sizeof(buffer)) == -1)
        perror("READ");
    std::string answer(buffer);
    return (answer);
}

std::vector<std::string> client::cmd_Inventory(void)
{
    std::string answer = server_answer(this->sock, "Inventory");
    std::vector<std::string> cont;
    size_t current = 0;
    size_t previous = 0;
    current = answer.find(",");

    if (answer.compare(0, 4, "DEAD") == 0) {
        cont.push_back("DEAD");
        return (cont);
    } else if (answer.compare(0, 2, "KO") == 0) {
        cont.push_back("KO");
        return (cont);
    }
    while (current != std::string::npos) {
        cont.push_back(answer.substr(previous, current - previous));
        previous = current + 2;
        current = answer.find(",", previous);
    }
    /* DEBUG: Print all values from cont*/
    std::cout <<  "Inventory :" << std::endl;
    int i = 0;
    for (auto ir = cont.begin(); ir != cont.end(); ++ir, i++)
        std::cout << i << " : " << *ir << std::endl;
    std::cout << std::endl;
    return (cont);
}

std::string client::cmd_Forward(void)
{
    std::string answer = server_answer(this->sock, "Forward");

    return (answer);
}

std::string client::cmd_Right(void)
{
    std::string answer = server_answer(this->sock, "Right");

    return (answer);
}

std::string client::cmd_Left(void)
{
    std::string answer = server_answer(this->sock, "Left");

    return (answer);
}

std::vector<std::string> client::cmd_Look(void)
{
    std::string answer = server_answer(this->sock, "Look");
    std::vector<std::string> cont;
    std::size_t current = 0;
    std::size_t previous = 0;
    current = answer.find(",");

    if (answer.compare(0, 4, "DEAD") == 0) {
        cont.push_back("DEAD");
        return (cont);
    } else if (answer.compare(0, 2, "KO") == 0) {
        cont.clear();
        return (cont);
    }
    while (current != std::string::npos) {
        cont.push_back(answer.substr(previous, current - previous));
        previous = current + 2;
        current = answer.find(",", previous);
    }
    std::cout <<  "Look :" << std::endl;
    int i = 0;
    for (auto ir = cont.begin(); ir != cont.end(); ++ir, i++)
        std::cout << i << " : " << *ir << std::endl;
    std::cout << std::endl;
    return (cont);
}

std::string client::cmd_Broadcast(std::string param)
{
    std::string str = "Broadcast \"" + param + "\"";
    std::string answer = server_answer(this->sock, str.c_str());

    return (answer);
}

std::string client::cmd_Connect(void)
{
    std::string answer = server_answer(this->sock, "Connect_nbr");

    return (answer);
}

std::string client::cmd_Fork(void)
{
    std::string answer = server_answer(this->sock, "Fork");

    return (answer);
}

std::string client::cmd_Eject(void)
{
    std::string answer = server_answer(this->sock, "Eject");

    return (answer);
}

std::string client::cmd_Take_obj(std::string param)
{
    std::string str = "Take " + param;
    std::string answer = server_answer(this->sock, str.c_str());

    return (answer);
}

std::string client::cmd_Set_obj(std::string param)
{
    std::string str = "Set " + param;
    std::string answer = server_answer(this->sock, str.c_str());

    return (answer);
}

std::string client::cmd_Incantation(void)
{
    std::string answer = server_answer(this->sock, "Incantation");

    return (answer);
}
