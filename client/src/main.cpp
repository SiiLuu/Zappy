/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** client my_teams
*/

#include "trantorian.hpp"

int main(int argc, char **argv)
{
    trantorian trantorian;
    help help;

    std::vector<std::string> av(argv, argv + argc);
    if (help.isWrongParameters(argc, av))
        return (ERROR);
    trantorian.machine = help.machine;
    trantorian.port = help.port;
    trantorian.teamName = help.teamName;
    trantorian.sock = connectClient(trantorian.port);
    if (trantorian.sock == ERROR)
        return (ERROR);
    trantorian.clientLoop(trantorian.sock);
    return (CORRECT);
}