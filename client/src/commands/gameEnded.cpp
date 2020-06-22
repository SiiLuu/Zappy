/*
** EPITECH PROJECT, 2020
** gameEnded.cpp
** File description:
** gameEnded.cpp
*/

#include "commandHandler.hpp"

void commandHandler::gameEnded(std::string command)
{
    std::string winnerTeam = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    winnerTeam.assign(commandVector.at(1));
    std::cout << "gameEnded" << std::endl;
}