/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** sfml
*/

#include "sfml.hpp"

Sfml::Sfml(int x, int y)
{
    this->x = x;
    this->y = y;
    this->_xView = x / 2 * 5;
    this->_yView = y / 2 * 5;
    this->createWindow();
    this->activeText = true;
}

Sfml::~Sfml() 
{
    for (size_t i = 0; i < _aplayer.size(); i++)
        delete this->_aplayer.at(i);
}

std::string Sfml::registerEvents()
{
    sf::View view = _window.getView();

    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            return ("CLOSE");
        if (this->_clock.getElapsedTime().asMilliseconds() > 75) {
            this->_clock.restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _xView >= 96) {
                view.move(-10, 0);
                _window.setView(view);
                _xView--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _xView <= this->x * 5 - 96) {
                view.move(10, 0);
                _window.setView(view);
                _xView++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _yView <= this->y * 5 - 54) {
                view.move(0, 10);
                _window.setView(view);
                _yView++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _yView >= 54) {
                view.move(0, -10);
                _window.setView(view);
                _yView--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                if (this->activeText == true)
                    this->activeText = false;
                else
                    this->activeText = true;
            }
        }
        this->display("\n");
    }
    return ("");
}

void Sfml::display(std::string object)
{
    std::istringstream str(object);
    std::vector<std::string> results(std::istream_iterator<std::string>{str},
        std::istream_iterator<std::string>());

    this->_window.clear();
    this->_window.draw(this->_sbckg);
    for (size_t i = 0; i < this->_smap.size(); i++)
        this->_window.draw(this->_smap.at(i));
    if (object.compare(0, 3, "bct") == 0)
        this->displayRsrc(results);
    if (object.compare(0, 3, "pnw") == 0)
        this->displayNewPlayers(results);
    if (object.compare(0, 3, "ppo") == 0)
        this->displayPlayers(results);
    if (object.compare(0, 3, "pic") == 0)
        this->displayInca(results);
    if (object.compare(0, 3, "pie") == 0)
        this->removeInca(results);
    if (object.compare(0, 3, "enw") == 0)
        this->displayEgg(results);
    if (object.compare(0, 3, "eht") == 0)
        this->removeEgg(results);
    if (object.compare(0, 3, "pdi") == 0)
        this->deathPlayers(results);
    if (object.compare(0, 3, "tna") == 0)
        this->displayHud(results);
    if (object.compare(0, 3, "pbc") == 0)
        this->displayBroad(results);
    for (size_t i = 0; i < this->_smap.size(); i++)
        this->_window.draw(this->_smap.at(i));
    for (size_t i = 0; i < _afood.size(); i++)
        this->_window.draw(this->_afood.at(i));
    for (size_t i = 0; i < _alinemate.size(); i++)
        this->_window.draw(this->_alinemate.at(i));
    for (size_t i = 0; i < _aderaumere.size(); i++)
        this->_window.draw(this->_aderaumere.at(i));
    for (size_t i = 0; i < _asibur.size(); i++)
        this->_window.draw(this->_asibur.at(i));
    for (size_t i = 0; i < _amendiane.size(); i++)
        this->_window.draw(this->_amendiane.at(i));
    for (size_t i = 0; i < _aphiras.size(); i++)
        this->_window.draw(this->_aphiras.at(i));
    for (size_t i = 0; i < _athystame.size(); i++)
        this->_window.draw(this->_athystame.at(i));
    for (size_t i = 0; i < _aegg.size(); i++)
        this->_window.draw(this->_aegg.at(i));
    for (size_t i = 0; i < _aplayer.size(); i++)
        this->_window.draw(this->_aplayer.at(i)->_splayer);
    for (size_t i = 0; i < _aincantation.size(); i++)
        this->_window.draw(this->_aincantation.at(i));
    for (size_t i = 0; i < _abroad.size(); i++)
        this->_window.draw(this->_abroad.at(i));
    if (this->activeText == true)
        this->_window.draw(this->teams);
    this->_window.display();
}

void Sfml::setRsrc()
{
    this->_tfood.loadFromFile("graphical/assets/items/melon.png");
    this->_sfood.setTexture(this->_tfood);
    this->_tlinemate.loadFromFile("graphical/assets/items/linemate.png");
    this->_slinemate.setTexture(this->_tlinemate);
    this->_tderaumere.loadFromFile("graphical/assets/items/deraumere.png");
    this->_sderaumere.setTexture(this->_tderaumere);
    this->_tsibur.loadFromFile("graphical/assets/items/sibur.png");
    this->_ssibur.setTexture(this->_tsibur);
    this->_tmendiane.loadFromFile("graphical/assets/items/mendiane.png");
    this->_smendiane.setTexture(this->_tmendiane);
    this->_tphiras.loadFromFile("graphical/assets/items/phiras.png");
    this->_sphiras.setTexture(this->_tphiras);
    this->_tthystame.loadFromFile("graphical/assets/items/thystame.png");
    this->_sthystame.setTexture(this->_tthystame);
    this->_tincantation.loadFromFile("graphical/assets/items/incantation.png");
    this->_sincantation.setTexture(this->_tincantation);
    this->_tegg.loadFromFile("graphical/assets/items/egg.png");
    this->_segg.setTexture(this->_tegg);
    this->_tplayer1.loadFromFile("graphical/assets/characters/level_1/standing/image.png");
    this->_tplayer2.loadFromFile("graphical/assets/characters/level_2/standing/image.png");
    this->_tplayer3.loadFromFile("graphical/assets/characters/level_3/standing/image.png");
    this->_tplayer4.loadFromFile("graphical/assets/characters/level_4/standing/image.png");
    this->_tplayer5.loadFromFile("graphical/assets/characters/level_5/standing/image.png");
    this->_tplayer6.loadFromFile("graphical/assets/characters/level_6/standing/image.png");
    this->_tplayer7.loadFromFile("graphical/assets/characters/level_7/standing/image.png");
    this->_tplayer8.loadFromFile("graphical/assets/characters/level_8/standing/image.png");
    this->_tplayer1death.loadFromFile("graphical/assets/characters/level_1/dying/image.png");
    this->_tplayer2death.loadFromFile("graphical/assets/characters/level_2/dying/image.png");
    this->_tplayer3death.loadFromFile("graphical/assets/characters/level_3/dying/image.png");
    this->_tplayer4death.loadFromFile("graphical/assets/characters/level_4/dying/image.png");
    this->_tplayer5death.loadFromFile("graphical/assets/characters/level_5/dying/image.png");
    this->_tplayer6death.loadFromFile("graphical/assets/characters/level_6/dying/image.png");
    this->_tplayer7death.loadFromFile("graphical/assets/characters/level_7/dying/image.png");
    this->_tplayer8death.loadFromFile("graphical/assets/characters/level_8/dying/image.png");
    this->font.loadFromFile("graphical/assets/text/font_bit.ttf");
    this->teams.setFont(this->font);
    this->teams.setPosition({float(5), float(10)});
    this->_tbroad.loadFromFile("graphical/assets/interactions/talk.png");
    this->_sbroad.setTexture(this->_tbroad);
    this->_sbroad.setScale(0.5, 0.5);
}

void Sfml::setMap()
{
    this->_tmap.loadFromFile("graphical/assets/map/grass.png");
    this->_smapCase.setTexture(this->_tmap);
    for (int i = 0; i < y; i++)
        for (int j = 0; j < this->x; j++) {
            this->_smapCase.setPosition({float(((1920 / 2) - ((this->x * 50) / 2)) + (j * 50)),
                float(((1080 / 2) - ((this->y * 49) / 2) - 32.5) + (i * 49))});
            this->_smap.push_back(this->_smapCase);
        }
}

void Sfml::setTexture()
{
    this->_tbckg.loadFromFile("graphical/assets/background/background.jpg");
    this->_sbckg.setTexture(this->_tbckg);
    this->setMap();
    this->setRsrc();
}

void Sfml::createWindow()
{
    this->_window.create(sf::VideoMode(1920, 1080), "ZAPPY");
    this->_window.setFramerateLimit(60);

    sf::View view = _window.getDefaultView();
    _window.setView(view);

    this->setTexture();
}
