/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** priority
*/

#ifndef PRIORITY_HPP_
#define PRIORITY_HPP_

#include "inventory.hpp"

class elevation
{
    public:
        elevation();
        ~elevation() = default;

        std::string compareLevelPriority(const int &level, std::vector<std::string> &vision, Inventory::Stones stones, Inventory::Food food);

        // all getter
        int getLinemate(const int &level) const;
        int getDeraumere(const int &level) const;
        int getSibur(const int &level) const;
        int getMendiane(const int &level) const;
        int getPhiras(const int &level) const;
        int getThystame(const int &level) const;
    private:

        // array of pointers to functions 
        std::string levelPriority1(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string levelPriority2(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string levelPriority3(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string levelPriority4(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string levelPriority5(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string levelPriority6(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string levelPriority7(std::vector<std::string> &vision, 
            Inventory::Stones, Inventory::Food);
        std::string (elevation::*LevelPriority[7])(std::vector<std::string> &vision,
            Inventory::Stones, Inventory::Food) = {
            &elevation::levelPriority1,
            &elevation::levelPriority2,
            &elevation::levelPriority3,
            &elevation::levelPriority4,
            &elevation::levelPriority5,
            &elevation::levelPriority6,
            &elevation::levelPriority7
        };

        std::vector<Inventory::Stones *> _incatantionTab;
};

#endif /* !PRIORITY_HPP_ */