/*
** EPITECH PROJECT, 2020
** startIncantation.cpp
** File description:
** startIncantation.cpp
*/

#include "commandHandler.hpp"

void commandHandler::startIncantation(std::string command)
{
    int posX = 0;
    int posY = 0;
    int incantLevel = 0;
    /* Players ... */
    std::vector<std::string> commandVector = this->strToWordVector(command);

    posX = std::stoi(commandVector.at(1));
    posY = std::stoi(commandVector.at(2));
    incantLevel = std::stoi(commandVector.at(3));
    /* switch(incantLevel) -> fill players attribute*/
    std::cout << "startIncantation" << std::endl;
}