/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** level_priority
*/

#include "elevation.hpp"

std::string elevation::levelPriority1(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getLinemate() < this->getLinemate(1) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::levelPriority2(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getLinemate() < this->getLinemate(2) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (stones.getSibur() < this->getSibur(2) && checkResources(Inventory::resources::sibur, vision))
        return "sibur";
    if (stones.getDeraumere() < this->getDeraumere(2) && checkResources(Inventory::resources::deraumere, vision))
        return "deraumere";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::levelPriority3(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getLinemate() < this->getLinemate(3) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (stones.getPhiras() < this->getPhiras(3) && checkResources(Inventory::resources::phiras, vision))
        return "phiras";
    if (stones.getSibur() < this->getSibur(3) && checkResources(Inventory::resources::sibur, vision))
        return "sibur";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::levelPriority4(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getSibur() < this->getSibur(4) && checkResources(Inventory::resources::sibur, vision))
        return "sibur";
    if (stones.getDeraumere() < this->getDeraumere(4) && checkResources(Inventory::resources::deraumere, vision))
        return "deraumere";
    if (stones.getLinemate() < this->getLinemate(4) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (stones.getPhiras() < this->getPhiras(4) && checkResources(Inventory::resources::phiras, vision))
        return "phiras";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::levelPriority5(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getMendiane() < this->getMendiane(5) && checkResources(Inventory::resources::mendiane, vision))
        return "mendiane";
    if (stones.getDeraumere() < this->getDeraumere(5) && checkResources(Inventory::resources::deraumere, vision))
        return "deraumere";
    if (stones.getSibur() < this->getSibur(5) && checkResources(Inventory::resources::sibur, vision))
        return "sibur";
    if (stones.getLinemate() < this->getLinemate(5) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::levelPriority6(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getSibur() < this->getSibur(6) && checkResources(Inventory::resources::sibur, vision))
        return "sibur";
    if (stones.getDeraumere() < this->getDeraumere(6) && checkResources(Inventory::resources::deraumere, vision))
        return "deraumere";
    if (stones.getLinemate() < this->getLinemate(6) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (stones.getPhiras() < this->getPhiras(6) && checkResources(Inventory::resources::phiras, vision))
        return "phiras";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::levelPriority7(std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    if (food.getStatus() == food.CRITICAL && checkResources(Inventory::resources::food, vision))
        return "food";
    if (stones.getLinemate() < this->getLinemate(7) && checkResources(Inventory::resources::linemate, vision))
        return "linemate";
    if (stones.getDeraumere() < this->getDeraumere(7) && checkResources(Inventory::resources::deraumere, vision))
        return "deraumere";
    if (stones.getSibur() < this->getSibur(7) && checkResources(Inventory::resources::sibur, vision))
        return "sibur";
    if (stones.getMendiane() < this->getMendiane(7) && checkResources(Inventory::resources::mendiane, vision))
        return "mendiane";
    if (stones.getPhiras() < this->getPhiras(7) && checkResources(Inventory::resources::phiras, vision))
        return "phiras";
    if (stones.getThystame() < this->getThystame(7) && checkResources(Inventory::resources::thystame, vision))
        return "thystame";
    if (food.getStatus() == food.WARNING && checkResources(Inventory::resources::food, vision))
        return "food";
    return "none";
}

std::string elevation::compareLevelPriority(const int &level, std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food)
{
    return (this->*LevelPriority[level - 1])(vision, stones, food);
}