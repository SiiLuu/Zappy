/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** inventory
*/

#include "inventory.hpp"

// class Stones
Inventory::Stones::Stones(int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame):
    _linemate(linemate), _deraumere(deraumere), _sibur(sibur), _mendiane(mendiane), _phiras(phiras), _thystame(thystame) {}

int Inventory::Stones::getLinemate() const { return _linemate;}
int Inventory::Stones::getDeraumere() const { return _deraumere;}
int Inventory::Stones::getSibur() const { return _sibur;}
int Inventory::Stones::getMendiane() const { return _mendiane;}
int Inventory::Stones::getPhiras() const { return _phiras;}
int Inventory::Stones::getThystame() const { return _thystame;}

void Inventory::Stones::setLinemate(const int &linemate) { _linemate = linemate;}
void Inventory::Stones::setDeraumere(const int &deraumere) { _deraumere = deraumere;}
void Inventory::Stones::setSibur(const int &sibur) { _sibur = sibur;}
void Inventory::Stones::setMendiane(const int &mendiane) { _mendiane = mendiane;}
void Inventory::Stones::setPhiras(const int &phiras) { _phiras = phiras;}
void Inventory::Stones::setThystame(const int &thystame) { _thystame = thystame;}


// class Food
Inventory::Food::Food(int units) : _units(units * TIME_UNITS) {}

int Inventory::Food::getUnits() const { return _units;}
int Inventory::Food::getLifePercent() const
{
    float calcul = this->getUnits();

    calcul /= (TIME_UNITS * 10);
    calcul *= 100;
    return  static_cast<int> (calcul);
}

void Inventory::Food::setUnits(const int &units) { _units = units * TIME_UNITS;}
void Inventory::Food::addUnits(const int &unit) { _units += unit * TIME_UNITS;}
void Inventory::Food::removeUnits(const int &units) { _units -= units;}

int Inventory::Food::getStatus()
{
    int lifePrecent = this->getLifePercent();

    if (lifePrecent < 30)
        return this->CRITICAL;
    else if (lifePrecent > 50)
        return this->OK;
    return this->WARNING;
}

static int find_int(std::string string)
{
    if (!string.compare("food"))
        return Inventory::resources::food;
    if (!string.compare("linemate"))
        return Inventory::resources::linemate;
    if (!string.compare("deraumere"))
        return Inventory::resources::deraumere;
    if (!string.compare("sibur"))
        return Inventory::resources::sibur;
    if (!string.compare("mendiane"))
        return Inventory::resources::mendiane;
    if (!string.compare("phiras"))
        return Inventory::resources::phiras;
    if (!string.compare("thystame"))
        return Inventory::resources::thystame;
    if (!string.compare("player"))
        return Inventory::resources::player;
    return Inventory::resources::none;
}

static std::vector<int> my_split(std::string string)
{
    std::vector<int> tab;
    size_t min = 0;

    for (size_t pos = string.find(" ", min); pos != std::string::npos
        && !string.empty();
        min = pos + 1, pos = string.find(" ", min))
        tab.push_back(find_int(string.substr(min, pos - min)));
    tab.push_back(find_int(string.substr(min, string.size())));
    return tab;
}

// enum Inventory
bool Inventory::checkResources(int resource, const std::vector<std::string> &vision)
{
    std::vector<int> tab;

    for (std::size_t index = 0; index < vision.size(); index++) {
        tab = my_split(vision.at(index));
        for (std::size_t i = 0; i < tab.size(); i++)
            if (resource == tab.at(i))
                return true;
        tab.clear();
    }
    return false;
}