/*
** EPITECH PROJECT, 2020
** eggLaid.cpp
** File description:
** eggLaid.cpp
*/

#include "commandHandler.hpp"

void commandHandler::eggLaid(std::string command)
{
    int eggNb = 0;
    int playerNb = 0;
    int posX = 0;
    int posY = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    eggNb = std::stoi(commandVector.at(1));
    playerNb = std::stoi(commandVector.at(2));
    posX = std::stoi(commandVector.at(3));
    posY = std::stoi(commandVector.at(4));
    std::cout << "eggLaid" << std::endl;
}