/*
** EPITECH PROJECT, 2020
** serverMessage.cpp
** File description:
** serverMessage.cpp
*/

#include "commandHandler.hpp"

void commandHandler::serverMessage(const std::string command)
{
    std::vector<std::string> commandVector = this->strToWordVector(command);
    std::string message;

    message = commandVector.at(1);
    std::cout << "serverMessage" << std::endl;
}