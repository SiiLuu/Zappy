/*
** EPITECH PROJECT, 2019
** myStrToWordVector.cpp
** File description:
** zappy
*/

#include "commandHandler.hpp"

std::vector<std::string> commandHandler::strToWordVector(const std::string line)
{
    std::vector<std::string> commandVector;
    std::string word;

    for (auto c : line) {
        if (c == ' ') {
            commandVector.push_back(word);
            word = "";
        } else {
            word = word + c;
        }
    }
    return (commandVector);
}