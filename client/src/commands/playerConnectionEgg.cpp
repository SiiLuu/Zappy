/*
** EPITECH PROJECT, 2020
** playerConnectionEgg.cpp
** File description:
** playerConnectionEgg.cpp
*/

#include "commandHandler.hpp"

void commandHandler::playerConnectionEgg(std::string command)
{
    int eggNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    eggNb = std::stoi(commandVector.at(1));
    std::cout << "playerConnectionEgg" << std::endl;
}