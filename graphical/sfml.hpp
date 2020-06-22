/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** sfml
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>

#ifndef SFML_HPP_
#define SFML_HPP_

class Player {
    
    public:

        Player();
        ~Player();

        int nb;
        int lvl;
        sf::Sprite _splayer;
};

class Sfml {

    public:

        Sfml(int, int);
        ~Sfml();
        void display(std::string);
        std::string registerEvents();

    private:

        // methods :

        void setTexture();
        void createWindow();
        void setRsrc();
        void setMap();
        void displayRsrc(std::vector<std::string>);
        void displayNewPlayers(std::vector<std::string>);
        void displayPlayers(std::vector<std::string>);
        void deathPlayers(std::vector<std::string>);
        void displayHud(std::vector<std::string>);
        void displayInca(std::vector<std::string>);
        void removeInca(std::vector<std::string>);
        void displayEgg(std::vector<std::string>);
        void removeEgg(std::vector<std::string>);
        void displayBroad(std::vector<std::string>);
        bool removeBroad(std::vector<std::string>);

        // vars :

        int x;
        int y;

        int _xView;
        int _yView;

        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock _clock;

        sf::Texture _tbckg;
        sf::Texture _tmap;
        sf::Texture _tlinemate;
        sf::Texture _tderaumere;
        sf::Texture _tsibur;
        sf::Texture _tmendiane;
        sf::Texture _tphiras;
        sf::Texture _tthystame;
        sf::Texture _tfood;
        sf::Texture _tplayer1;
        sf::Texture _tplayer2;
        sf::Texture _tplayer3;
        sf::Texture _tplayer4;
        sf::Texture _tplayer5;
        sf::Texture _tplayer6;
        sf::Texture _tplayer7;
        sf::Texture _tplayer8;
        sf::Texture _tplayer1death;
        sf::Texture _tplayer2death;
        sf::Texture _tplayer3death;
        sf::Texture _tplayer4death;
        sf::Texture _tplayer5death;
        sf::Texture _tplayer6death;
        sf::Texture _tplayer7death;
        sf::Texture _tplayer8death;
        sf::Texture _tincantation;
        sf::Texture _tegg;
        sf::Texture _tbroad;

        sf::Sprite _sbckg;
        sf::Sprite _smapCase;
        sf::Sprite _slinemate;
        sf::Sprite _sderaumere;
        sf::Sprite _ssibur;
        sf::Sprite _smendiane;
        sf::Sprite _sphiras;
        sf::Sprite _sthystame;
        sf::Sprite _sfood;
        sf::Sprite _sincantation;
        sf::Sprite _segg;
        sf::Sprite _sbroad;

        std::vector<sf::Sprite> _smap;
        std::vector<sf::Sprite> _alinemate;
        std::vector<sf::Sprite> _aderaumere;
        std::vector<sf::Sprite> _asibur;
        std::vector<sf::Sprite> _amendiane;
        std::vector<sf::Sprite> _aphiras;
        std::vector<sf::Sprite> _athystame;
        std::vector<sf::Sprite> _afood;
        std::vector<sf::Sprite> _aincantation;
        std::vector<sf::Sprite> _aegg;
        std::vector<sf::Sprite> _abroad;

        std::vector<Player *> _aplayer;

        sf::Font font;
        sf::Text teams;
        bool activeText;
};

#endif /* !SFML_HPP_ */
