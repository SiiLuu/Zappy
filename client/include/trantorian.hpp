/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** trantorian
*/

#ifndef TRANTORIAN_HPP_
#define TRANTORIAN_HPP_

// #include "state_machine.hpp"
#include "inventory.hpp"
#include "path_finding.hpp"
#include "elevation.hpp"
#include "client.hpp"
#include "commandHandler.hpp"

static const int DEAD = -1;

class trantorian : public elevation, public client, public Path, public commandHandler
{
    public:
        trantorian(int level = 1);
        ~trantorian() = default;

        int clientLoop(int) override;

    private:
        void which_command(std::string) override;
        int move_to_resource(std::string resource, std::vector<std::string> vision);
        int check_cmd(std::string cmd_result);
        int check_fork(void);
        bool checkElevation(void);
        void fillInventory(std::vector<std::string> inventory);
        void parseItem(std::string item);
        void initItemTypesVector();
        int state_machine(void);
        void iaLoop(int clientSocket) override;

        std::vector<std::string> itemTypes;
        Inventory::Food _food;
        Inventory::Stones _stones;
        int _level;
};

#endif /* !TRANTORIAN_HPP_ */