/*
** EPITECH PROJECT, 2020
** expulsion.cpp
** File description:
** expulsion.cpp
*/

#include "commandHandler.hpp"

void commandHandler::expulsion(std::string command)
{
    int playerExpNb = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    playerExpNb = std::stoi(commandVector.at(1));
    std::cout << "expulsion" << std::endl;
}