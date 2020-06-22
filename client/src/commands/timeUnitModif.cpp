/*
** EPITECH PROJECT, 2020
** timeUnitModif.cpp
** File description:
** timeUnitModif.cpp
*/

#include "commandHandler.hpp"

void commandHandler::timeUnitModif(std::string command)
{
    int timeUnit = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    timeUnit = std::stoi(commandVector.at(1));
    std::cout << "timeUnitModif" << std::endl;
}