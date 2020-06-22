/*
** EPITECH PROJECT, 2020
** graphical
** File description:
** players
*/

#include "sfml.hpp"

Player::Player() {}

Player::~Player() {}

void Sfml::displayNewPlayers(std::vector<std::string> results)
{
    int _nb = 0;
    std::string number = results.at(1);
    int _x = std::stoi(results.at(2));
    int _y = std::stoi(results.at(3));
    int _level = std::stoi(results.at(5));
    Player *player = new Player();

    number.erase(0, 1);
    _nb = std::stoi(number);
    player->nb = _nb;
    player->lvl = _level;
    if (_level == 1) {
        player->_splayer.setTexture(this->_tplayer1);
        player->_splayer.setTextureRect(sf::IntRect(23 * 2, 44 * 2, 23, 44));
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
    } else if (_level == 2) {
        player->_splayer.setTexture(this->_tplayer2);
        player->_splayer.setTextureRect(sf::IntRect(32 * 2, 61 * 2, 32, 61));
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 10)});
    } else if (_level == 3) {
        player->_splayer.setTexture(this->_tplayer3);
        player->_splayer.setTextureRect(sf::IntRect(53 * 2, 59 * 2, 53, 59));
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
    } else if (_level == 4) {
        player->_splayer.setTexture(this->_tplayer4);
        player->_splayer.setTextureRect(sf::IntRect(28 * 2, 46 * 2, 28, 46));
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
    } else if (_level == 5) {
        player->_splayer.setTexture(this->_tplayer5);
        player->_splayer.setTextureRect(sf::IntRect(32 * 2, 52 * 2, 32, 52));
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
    } else if (_level == 6) {
        player->_splayer.setTexture(this->_tplayer6);
        player->_splayer.setTextureRect(sf::IntRect(39 * 2, 55 * 2, 39, 55));
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
    } else if (_level == 7) {
        player->_splayer.setTexture(this->_tplayer7);
        player->_splayer.setTextureRect(sf::IntRect(63 * 2, 80 * 2, 63, 80));
        player->_splayer.setScale(0.75, 0.75);
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 5),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
    } else if (_level == 8) {
        player->_splayer.setTexture(this->_tplayer8);
        player->_splayer.setTextureRect(sf::IntRect(64 * 2, 83 * 2, 64, 83));
        player->_splayer.setScale(0.7, 0.7);
        player->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 10),
            float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
    }
    this->_aplayer.push_back(player);
}

void Sfml::displayPlayers(std::vector<std::string> results)
{
    int _nb = std::stoi(results.at(1));
    int _x = std::stoi(results.at(2));
    int _y = std::stoi(results.at(3));
    int _level = std::stoi(results.at(4));

    for (size_t i = 0; i < _aplayer.size(); i++) {
        if (_aplayer.at(i)->nb == _nb && _aplayer.at(i)->lvl != _level) {
            if (_level == 1) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer1);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(23 * 2, 44 * 2, 23, 44));
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
            } else if (_level == 2) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer2);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(32 * 2, 61 * 2, 32, 61));
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 10)});
            } else if (_level == 3) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer3);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(53 * 2, 59 * 2, 53, 59));
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
            } else if (_level == 4) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer4);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(28 * 2, 46 * 2, 28, 46));
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
            } else if (_level == 5) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer5);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(32 * 2, 52 * 2, 32, 52));
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
            } else if (_level == 6) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer6);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(39 * 2, 55 * 2, 39, 55));
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 14),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49))});
            } else if (_level == 7) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer7);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(63 * 2, 80 * 2, 63, 80));
                _aplayer.at(i)->_splayer.setScale(0.75, 0.75);
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 5),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
            } else if (_level == 8) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer8);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(64 * 2, 83 * 2, 64, 83));
                _aplayer.at(i)->_splayer.setScale(0.7, 0.7);
                _aplayer.at(i)->_splayer.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 10),
                    float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
            }
            _aplayer.at(i)->lvl = _level;
        } else if (_aplayer.at(i)->nb == _nb && _aplayer.at(i)->lvl == _level) {
            _aplayer.at(i)->_splayer.setPosition(
                {float(((1920 / 2) - ((this->x * 50) / 2)) + (_x * 50) + 10),
                float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (_y * 49) - 5)});
        }
    }
}

void Sfml::deathPlayers(std::vector<std::string> results)
{
    int _nb = std::stoi(results.at(1));

    for (size_t i = 0; i < _aplayer.size(); i++) {
        if (_aplayer.at(i)->nb == _nb) {
            if (_aplayer.at(i)->lvl == 1) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer1death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(50 * 16, 44 * 2, 50, 44));
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 10,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 15});
            } else if (_aplayer.at(i)->lvl == 2) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer2death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(99 * 11, 62 * 2, 99, 62));
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 10,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 15});
            } else if (_aplayer.at(i)->lvl == 3) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer3death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(76 * 12, 77 * 2, 76, 77));
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 5,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 17});
            } else if (_aplayer.at(i)->lvl == 4) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer4death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(46 * 11, 48 * 3, 46, 48));
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 4,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 15});
            } else if (_aplayer.at(i)->lvl == 5) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer5death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(76 * 12, 48 * 3, 76, 48));
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 15,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 5});
            } else if (_aplayer.at(i)->lvl == 6) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer6death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(52 * 11, 56 * 3, 52, 56));
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 7,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 12});
            } else if (_aplayer.at(i)->lvl == 7) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer7death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(98 * 10, 75 * 2, 98, 75));
                _aplayer.at(i)->_splayer.setScale(0.65, 0.65);
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 5,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 15});
            } else if (_aplayer.at(i)->lvl == 8) {
                _aplayer.at(i)->_splayer.setTexture(this->_tplayer8death);
                _aplayer.at(i)->_splayer.setTextureRect(sf::IntRect(98 * 10, 81 * 2, 98, 81));
                _aplayer.at(i)->_splayer.setScale(0.7, 0.7);
                _aplayer.at(i)->_splayer.setPosition({_aplayer.at(i)->_splayer.getPosition().x - 8,
                    _aplayer.at(i)->_splayer.getPosition().y + 1 + 15});
            }
        }
    }
}
