/*
** EPITECH PROJECT, 2020
** eggHatching.cpp
** File description:
** eggHatching.cpp
*/

#include "commandHandler.hpp"

void commandHandler::eggHatching(std::string command)
{
    int eggNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    eggNb = std::stoi(commandVector.at(1));
    std::cout << "eggHatching" << std::endl;
}