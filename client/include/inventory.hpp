/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** inventory
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <vector>
#include <string>

namespace Inventory
{
    class Stones
    {
        public:
            Stones(int linemate = 0, int deraumere = 0, int sibur = 0, int mendiane = 0, int phiras = 0, int thystame = 0);
            ~Stones() = default;

            // all getter
            int getLinemate() const;
            int getDeraumere() const;
            int getSibur() const;
            int getMendiane() const;
            int getPhiras() const;
            int getThystame() const;

            // all setter
            void setLinemate(const int &linemate);
            void setDeraumere(const int &deraumere);
            void setSibur(const int &sibur);
            void setMendiane(const int &mendiane);
            void setPhiras(const int &phiras);
            void setThystame(const int &thystame);

        private:
            int _linemate;
            int _deraumere;
            int _sibur;
            int _mendiane;
            int _phiras;
            int _thystame;
    };

    class Food
    {
        public:
            Food(int units = 10);
            ~Food() = default;

            enum FoodStatus {
                OK,
                WARNING,
                CRITICAL,
            };

            // all getter
            int getUnits() const;
            int getStatus();
            int getLifePercent() const;

            // all setter
            void setUnits(const int &units);

            void addUnits(const int &unit);
            void removeUnits(const int &units);

        private:
            const int TIME_UNITS = 126;
            int _units;
    };

    enum resources {
        none,
        food,
        linemate,
        deraumere,
        sibur,
        mendiane,
        phiras,
        thystame,
        player
    };

    bool checkResources(int resource, const std::vector<std::string> &vision);
}

#endif /* !INVENTORY_HPP_ */