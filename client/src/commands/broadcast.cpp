/*
** EPITECH PROJECT, 2020
** broadcast.cpp
** File description:
** broadcast.cpp
*/

#include "commandHandler.hpp"

void commandHandler::broadcast(std::string command)
{
    int playerNb = 0;
    std::string message;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    message.assign(commandVector.at(2));
    std::cout << "broadcast" << std::endl;
}