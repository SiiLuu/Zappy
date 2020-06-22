/*
** EPITECH PROJECT, 2020
** playerConnection.cpp
** File description:
** playerConnection.cpp
*/

#include "commandHandler.hpp"

void commandHandler::playerConnection(std::string command)
{
    int playerNb = 0;
    int posX = 0;
    int posY = 0;
    int orientation = 0;
    int level = 0;
    std::string teamName;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    posX = std::stoi(commandVector.at(2));
    posY = std::stoi(commandVector.at(3));
    orientation = std::stoi(commandVector.at(4));
    level = std::stoi(commandVector.at(5));
    teamName.assign(commandVector.at(6));
    std::cout << "playerConnection" << std::endl;
}