/*
** EPITECH PROJECT, 2020
** timeUnitRequest.cpp
** File description:
** timeUnitRequest.cpp
*/

#include "commandHandler.hpp"

void commandHandler::timeUnitRequest(std::string command)
{
    int timeUnit = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    timeUnit = std::stoi(commandVector.at(1));
    std::cout << "timeUnitRequest" << std::endl;
}