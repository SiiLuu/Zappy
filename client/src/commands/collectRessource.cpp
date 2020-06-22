/*
** EPITECH PROJECT, 2020
** collectRessource.cpp
** File description:
** collectRessource.cpp
*/

#include "commandHandler.hpp"

void commandHandler::collectRessource(std::string command)
{
    int playerNb = 0;
    int resourceNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    resourceNb = std::stoi(commandVector.at(2));
    std::cout << "collectRessource" << std::endl;
}