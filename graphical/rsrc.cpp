/*
** EPITECH PROJECT, 2020
** graphical
** File description:
** rsrc
*/

#include "sfml.hpp"

void Sfml::displayRsrc(std::vector<std::string> results)
{
    int _x = std::stoi(results.at(1));
    int _y = std::stoi(results.at(2));
    int _q0 = std::stoi(results.at(3));
    int _q1 = std::stoi(results.at(4));
    int _q2 = std::stoi(results.at(5));
    int _q3 = std::stoi(results.at(6));
    int _q4 = std::stoi(results.at(7));
    int _q5 = std::stoi(results.at(8));
    int _q6 = std::stoi(results.at(9));

    for (int i = 0; i < _q0; i++) {
        this->_sfood.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 7),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 7)});
        this->_afood.push_back(this->_sfood);
    }
    for (int i = 0; i < _q1; i++) {
        this->_slinemate.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 24),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 10)});
        this->_alinemate.push_back(this->_slinemate);
    }
    for (int i = 0; i < _q2; i++) {
        this->_sderaumere.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 35),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 10)});
        this->_aderaumere.push_back(this->_sderaumere);
    }
    for (int i = 0; i < _q3; i++) {
        this->_ssibur.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 10),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 27)});
        this->_asibur.push_back(this->_ssibur);
    }
    for (int i = 0; i < _q4; i++) {
        this->_smendiane.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 18),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 27)});
        this->_amendiane.push_back(this->_smendiane);
    }
    for (int i = 0; i < _q5; i++) {
        this->_sphiras.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 26),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 27)});
        this->_aphiras.push_back(this->_sphiras);
    }
    for (int i = 0; i < _q6; i++) {
        this->_sthystame.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 35),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) + 27)});
        this->_athystame.push_back(this->_sthystame);
    }
}
