/*
** EPITECH PROJECT, 2020
** graphical
** File description:
** hud
*/

#include "sfml.hpp"

void Sfml::displayHud(std::vector<std::string> results)
{
    std::string teamName = results.at(1);

    if (this->teams.getString().getSize() > 0)
        this->teams.setString(this->teams.getString() + " VS " + teamName);
    else
        this->teams.setString(teamName);
}

bool Sfml::removeBroad(std::vector<std::string> results)
{
    int _nb = std::stoi(results.at(1));
    sf::Vector2f pos1 = {0, 0};
    sf::Vector2f pos2 = {0, 0};

    for (size_t i = 0; i < _aplayer.size(); i++) {
        if (_aplayer.at(i)->nb == _nb) {
            pos1 = _aplayer.at(i)->_splayer.getPosition();
            break;
        }
    }
    pos2 = {pos1.x - 12, pos1.y - 17};
    for (size_t i = 0; i < _abroad.size(); i++)
        if (_abroad.at(i).getPosition() == pos2) {
            _abroad.erase(_abroad.begin() + i);
            std::cout << i << std::endl;
            return (true);
        }
    return (false);
}

void Sfml::displayBroad(std::vector<std::string> results)
{
    int _nb = std::stoi(results.at(1));

    if (removeBroad(results) == true)
        return;
    for (size_t i = 0; i < _aplayer.size(); i++) {
        if (_aplayer.at(i)->nb == _nb) {
            this->_sbroad.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 12,
                _aplayer.at(i)->_splayer.getPosition().y - 17});
            this->_abroad.push_back(this->_sbroad);
        }
    }
}
