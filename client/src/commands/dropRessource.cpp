/*
** EPITECH PROJECT, 2020
** dropRessource.cpp
** File description:
** dropRessource.cpp
*/

#include "commandHandler.hpp"

void commandHandler::dropRessource(std::string command)
{
    int playerNb = 0;
    int resourceNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    resourceNb = std::stoi(commandVector.at(2));
    std::cout << "dropRessource" << std::endl;
}