/*
** EPITECH PROJECT, 2020
** layEgg.cpp
** File description:
** layEgg.cpp
*/

#include "commandHandler.hpp"

void commandHandler::layEgg(std::string command)
{
    int eggNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    eggNb = std::stoi(commandVector.at(1));
    std::cout << "layEgg" << std::endl;
}