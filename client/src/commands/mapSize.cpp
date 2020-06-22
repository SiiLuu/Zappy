/*
** EPITECH PROJECT, 2020
** mapSize.cpp
** File description:
** mapSize.cpp
*/

#include "commandHandler.hpp"

void commandHandler::mapSize(const std::string command)
{
    int x = 0;
    int y = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    x = std::stoi(commandVector.at(1));
    y = std::stoi(commandVector.at(2));
    std::cout << "mapSize" << std::endl;
}