/*
** EPITECH PROJECT, 2020
** endIncantation.cpp
** File description:
** endIncantation.cpp
*/

#include "commandHandler.hpp"

void commandHandler::endIncantation(std::string command)
{
    int posX = 0;
    int posY = 0;
    /* Incantation result ? int ? string ?*/
    std::vector<std::string> commandVector = this->strToWordVector(command);

    posX = std::stoi(commandVector.at(1));
    posY = std::stoi(commandVector.at(2));
    /* Incantation result = ...*/
    std::cout << "endIncantation" << std::endl;
}