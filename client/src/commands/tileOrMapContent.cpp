/*
** EPITECH PROJECT, 2020
** tileOrMapContent.cpp
** File description:
** tileOrMapContent.cpp
*/

#include "commandHandler.hpp"

void commandHandler::tileOrMapContent(std::string command)
{
    int posX = 0;
    int posY = 0;
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    int res4 = 0;
    int res5 = 0;
    int res6 = 0;
    std::vector<std::string> commandVector = this->strToWordVector(command);

    posX = std::stoi(commandVector.at(1));
    posY = std::stoi(commandVector.at(2));
    res0 = std::stoi(commandVector.at(3));
    res1 = std::stoi(commandVector.at(4));
    res2 = std::stoi(commandVector.at(5));
    res3 = std::stoi(commandVector.at(6));
    res4 = std::stoi(commandVector.at(7));
    res5 = std::stoi(commandVector.at(8));
    res6 = std::stoi(commandVector.at(9));
    std::cout << "tileOrMapContent" << std::endl;
}