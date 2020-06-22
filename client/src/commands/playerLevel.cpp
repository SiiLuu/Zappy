/*
** EPITECH PROJECT, 2020
** playerLevel.cpp
** File description:
** playerLevel.cpp
*/

#include "commandHandler.hpp"

void commandHandler::playerLevel(const std::string command)
{
    int playerNb;
    int level;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    level = std::stoi(commandVector.at(2));
    std::cout << "playerLevel" << std::endl;
}