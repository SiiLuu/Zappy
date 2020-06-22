/*
** EPITECH PROJECT, 2020
** hatchedEggDeath.cpp
** File description:
** hatchedEggDeath.cpp
*/

#include "commandHandler.hpp"

void commandHandler::hatchedEggDeath(std::string command)
{
    int eggNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    eggNb = std::stoi(commandVector.at(1));
    std::cout << "hatchedEggDeath" << std::endl;
}