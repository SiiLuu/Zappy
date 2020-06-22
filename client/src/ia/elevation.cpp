/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** priority
*/

#include "elevation.hpp"

elevation::elevation()
{
    this->_incatantionTab.push_back(new Inventory::Stones(1));
    this->_incatantionTab.push_back(new Inventory::Stones(1, 1, 1));
    this->_incatantionTab.push_back(new Inventory::Stones(2, 0, 1, 0, 2));
    this->_incatantionTab.push_back(new Inventory::Stones(1, 1, 2, 0, 1));
    this->_incatantionTab.push_back(new Inventory::Stones(1, 2, 1, 3));
    this->_incatantionTab.push_back(new Inventory::Stones(1, 2, 3, 0, 1));
    this->_incatantionTab.push_back(new Inventory::Stones(2, 2, 2, 2, 2, 1));
}

int elevation::getLinemate(const int &level) const { return _incatantionTab[level - 1]->getLinemate();}
int elevation::getDeraumere(const int &level) const { return _incatantionTab[level - 1]->getDeraumere();}
int elevation::getSibur(const int &level) const { return _incatantionTab[level - 1]->getSibur();}
int elevation::getMendiane(const int &level) const { return _incatantionTab[level - 1]->getMendiane();}
int elevation::getPhiras(const int &level) const { return _incatantionTab[level - 1]->getPhiras();}
int elevation::getThystame(const int &level) const { return _incatantionTab[level - 1]->getThystame();}