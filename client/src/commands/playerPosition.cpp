/*
** EPITECH PROJECT, 2020
** playerPosition.cpp
** File description:
** playerPosition.cpp
*/

#include "commandHandler.hpp"

void commandHandler::playerPosition(const std::string command)
{
    int playerNb;
    int posX;
    int posY;
    int orientation;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    posX = std::stoi(commandVector.at(2));
    posY = std::stoi(commandVector.at(3));
    orientation = std::stoi(commandVector.at(4));
    std::cout << "playerPosition" << std::endl;
}