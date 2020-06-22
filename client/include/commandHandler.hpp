/*
** EPITECH PROJECT, 2020
** commandHandler.hpp
** File description:
** commandHandler.hpp
*/

#ifndef COMMANDHandler_H_
#define COMMANDHandler_H_

#include <string>
#include <vector>
#include <iostream>

class commandHandler
{
    public:
        commandHandler();
        ~commandHandler();
        std::vector<std::string> strToWordVector(std::string);
    private:
        void (commandHandler::*methodPointersArray[25])(const std::string);
        std::vector<std::string> commandList;
        void initMethodPointerArray();
        void initMethodNameArray();
        void parseCommand(const std::string);
        void mapSize(const std::string);
        void tileOrMapContent(const std::string);
        void teamsName(const std::string);
        void playerConnection(const std::string);
        void playerPosition(const std::string);
        void playerLevel(const std::string);
        void playerInventory(const std::string);
        void expulsion(const std::string);
        void broadcast(const std::string);
        void startIncantation(const std::string);
        void endIncantation(const std::string);
        void layEgg(const std::string);
        void dropRessource(const std::string);
        void collectRessource(const std::string);
        void playerDeath(const std::string);
        void eggLaid(const std::string);
        void eggHatching(const std::string);
        void playerConnectionEgg(const std::string);
        void hatchedEggDeath(const std::string);
        void timeUnitRequest(const std::string);
        void timeUnitModif(const std::string);
        void gameEnded(const std::string);
        void serverMessage(const std::string);
        void unknownCommand(const std::string);
        void commandParameter(const std::string);
};




#endif /* !COMMANDHandler_H */