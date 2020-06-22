/*
** EPITECH PROJECT, 2020
** commandHandler.cpp
** File description:
** commandHandler.cpp
*/

#include "commandHandler.hpp"

commandHandler::commandHandler()
{
    this->initMethodPointerArray();
}

commandHandler::~commandHandler()
{
}

void commandHandler::initMethodPointerArray()
{
    this->methodPointersArray[0] = &commandHandler::mapSize;
    this->methodPointersArray[1] = &commandHandler::tileOrMapContent;
    this->methodPointersArray[2] = &commandHandler::teamsName;
    this->methodPointersArray[3] = &commandHandler::playerConnection;
    this->methodPointersArray[4] = &commandHandler::playerPosition;
    this->methodPointersArray[5] = &commandHandler::playerLevel;
    this->methodPointersArray[6] = &commandHandler::playerInventory;
    this->methodPointersArray[7] = &commandHandler::expulsion;
    this->methodPointersArray[8] = &commandHandler::broadcast;
    this->methodPointersArray[9] = &commandHandler::startIncantation;
    this->methodPointersArray[10] = &commandHandler::endIncantation;
    this->methodPointersArray[11] = &commandHandler::layEgg;
    this->methodPointersArray[12] = &commandHandler::dropRessource;
    this->methodPointersArray[13] = &commandHandler::collectRessource;
    this->methodPointersArray[14] = &commandHandler::playerDeath;
    this->methodPointersArray[15] = &commandHandler::eggLaid;
    this->methodPointersArray[16] = &commandHandler::eggHatching;
    this->methodPointersArray[17] = &commandHandler::playerConnectionEgg;
    this->methodPointersArray[18] = &commandHandler::hatchedEggDeath;
    this->methodPointersArray[19] = &commandHandler::timeUnitRequest;
    this->methodPointersArray[20] = &commandHandler::timeUnitModif;
    this->methodPointersArray[21] = &commandHandler::gameEnded;
    this->methodPointersArray[22] = &commandHandler::serverMessage;
    this->methodPointersArray[23] = &commandHandler::unknownCommand;
    this->methodPointersArray[24] = &commandHandler::commandParameter;
}

void commandHandler::initMethodNameArray()
{
    this->commandList.push_back("msz");
    this->commandList.push_back("bct");
    this->commandList.push_back("tna");
    this->commandList.push_back("pnw");
    this->commandList.push_back("ppo");
    this->commandList.push_back("plv");
    this->commandList.push_back("pin");
    this->commandList.push_back("pex");
    this->commandList.push_back("pbc");
    this->commandList.push_back("pic");
    this->commandList.push_back("pie");
    this->commandList.push_back("pfk");
    this->commandList.push_back("pdr");
    this->commandList.push_back("pgt");
    this->commandList.push_back("pdi");
    this->commandList.push_back("enw");
    this->commandList.push_back("eht");
    this->commandList.push_back("ebo");
    this->commandList.push_back("edi");
    this->commandList.push_back("sgt");
    this->commandList.push_back("sst");
    this->commandList.push_back("seg");
    this->commandList.push_back("smg");
    this->commandList.push_back("suc");
    this->commandList.push_back("sbp");
}

void commandHandler::parseCommand(const std::string command)
{
    std::string cmdWord = command.substr(0, command.find_first_of(' '));
    size_t index = 0;
    std::cout << cmdWord << std::endl;

    for (std::vector<std::string>::iterator it = this->commandList.begin(); it != this->commandList.end(); ++it, index++) {
        std::cout << *it << std::endl;
        if (it->compare(cmdWord) == 0) {
            (this->*methodPointersArray[index])(command);
        }
    }
}