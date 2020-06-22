/*
** EPITECH PROJECT, 2020
** playerInventory.cpp
** File description:
** playerInventory.cpp
*/

#include "commandHandler.hpp"

void commandHandler::playerInventory(const std::string command)
{
    int playerNb;
    int posX;
    int posY;
    std::vector<int> inventory;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerNb = std::stoi(commandVector.at(1));
    posX = std::stoi(commandVector.at(2));
    posY = std::stoi(commandVector.at(3));
    for (std::vector<std::string>::iterator it = commandVector.begin(); it != commandVector.end(); ++it) {
        if (std::stoi(*it) != playerNb || std::stoi(*it) != posX || std::stoi(*it) != posY) {
            inventory.push_back(std::stoi(*it));
        }
    }
    std::cout << "playerInventory" << std::endl;
}