/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** egg
*/

#include "sfml.hpp"

void Sfml::displayEgg(std::vector<std::string> results)
{
    int _x = std::stoi(results.at(3));
    int _y = std::stoi(results.at(4));

    this->_segg.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 22),
        float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 10)});
    this->_aegg.push_back(this->_segg);
}

void Sfml::removeEgg(std::vector<std::string> results)
{
    int _x = std::stoi(results.at(1));
    int _y = std::stoi(results.at(2));
    sf::Vector2f pos = {float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 22),
        float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 10)};

    for (size_t i = 0; i < _aegg.size(); i++) {
        if (_aegg.at(i).getPosition() == pos)
            _aegg.erase(_aegg.begin() + i);
    }
}
