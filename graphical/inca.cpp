/*
** EPITECH PROJECT, 2020
** graphical
** File description:
** inca
*/

#include "sfml.hpp"

void Sfml::removeInca(std::vector<std::string> results)
{
    int _x = std::stoi(results.at(1));
    int _y = std::stoi(results.at(2));
    sf::Vector2f pos = {float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 3),
        float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))};

    for (size_t i = 0; i < _aincantation.size(); i++) {
        if (_aincantation.at(i).getPosition() == pos)
            _aincantation.erase(_aincantation.begin() + i);
    }
}

void Sfml::displayInca(std::vector<std::string> results)
{
    int _x = std::stoi(results.at(1));
    int _y = std::stoi(results.at(2));

    this->_sincantation.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 3),
        float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
    this->_aincantation.push_back(this->_sincantation);
    
}
