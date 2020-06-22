/*
** EPITECH PROJECT, 2020
** help
** File description:
** help.cpp
*/

#include "client.hpp"

help::help()
{
    this->machine = "localhost";
}

help::~help()
{
}

bool help::checkParameters(std::vector<std::string> av)
{
    for (std::vector<std::string>::iterator it = av.begin() ; it != av.end(); ++it) {
        if (it->compare("-h") == 0) {
            this->machine.assign(av.at(it - av.begin() + 1));
        } else if (it->compare("-p") == 0) {
            this->port = std::stoi(av.at(it - av.begin() + 1));
            if ((this->port) < 0) {
                std::cout << "The port must be greater than 0." << std::endl;
                return (true);
            }
        } else if (it->compare("-n") == 0) {
            this->teamName.assign(av.at(it - av.begin() + 1));
        }
    }
    return (false);
}

bool help::isWrongParameters(int argc, std::vector<std::string> av)
{
    if (argc == 2 && av.at(1).compare("-help") == 0) {
        std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
        std::cout << "       port\tis the port number" << std::endl;
        std::cout << "       name\tis the name of the team" << std::endl;
        std::cout << "       machine\t is the name of the machine; localhost by default" << std::endl;
        return (true);
    } else if (argc != 5 && argc != 7) {
        std::cout << "Wrong parameters." << std::endl;
        return (true);
    }
    return (this->checkParameters(av));
}