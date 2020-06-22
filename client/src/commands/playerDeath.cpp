/*
** EPITECH PROJECT, 2020
** playerDeath.cpp
** File description:
** playerDeath.cpp
*/

#include "commandHandler.hpp"

void commandHandler::playerDeath(std::string command)
{
    int playerNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    std::cout << "playerDeath" << std::endl;
}