/*
** EPITECH PROJECT, 2020
** elevation.c
** File description:
** elevation.c
*/

#include "server.h"

bool elevation_lvl_one(client_t *client, int *array_player)
{
    int size = 0;

    for (; array_player[size] != -1; size++);
    if (size < 1 || client->player->inv->linemate < 1)
        return (false);
    client->player->inv->linemate -= 1;
    client->player->player_lvl = 2;
    return (true);
}

bool elevation_lvl_two(server_t *server, int *array_player)
{
    int size = 0;

    for (; array_player[size] != -1; size++);
    if (size < 2)
        return (false);
    if (server->clients[array_player[0]]->player->inv->linemate < 1
        || server->clients[array_player[0]]->player->inv->deraumere < 1
        || server->clients[array_player[0]]->player->inv->sibur < 1
        || server->clients[array_player[1]]->player->inv->linemate < 1
        || server->clients[array_player[1]]->player->inv->deraumere < 1
        || server->clients[array_player[1]]->player->inv->sibur < 1)
        return (false);
    server->clients[array_player[0]]->player->inv->linemate -= 1;
    server->clients[array_player[0]]->player->inv->deraumere -= 1;
    server->clients[array_player[0]]->player->inv->sibur -= 1;
    server->clients[array_player[0]]->player->player_lvl = 3;
    server->clients[array_player[1]]->player->inv->linemate -= 1;
    server->clients[array_player[1]]->player->inv->deraumere -= 1;
    server->clients[array_player[1]]->player->inv->sibur -= 1;
    server->clients[array_player[1]]->player->player_lvl = 3;
    return (true);
}

bool elevation_lvl_three(server_t *server, int *array_player)
{
    int size = 0;

    for (; array_player[size] != -1; size++);
    if (size < 2)
        return (false);
    if (server->clients[array_player[0]]->player->inv->linemate < 2
        || server->clients[array_player[0]]->player->inv->phiras < 2
        || server->clients[array_player[0]]->player->inv->sibur < 1
        || server->clients[array_player[1]]->player->inv->linemate < 2
        || server->clients[array_player[1]]->player->inv->phiras < 2
        || server->clients[array_player[1]]->player->inv->sibur < 1)
        return (false);
    server->clients[array_player[0]]->player->inv->linemate -= 2;
    server->clients[array_player[0]]->player->inv->phiras -= 2;
    server->clients[array_player[0]]->player->inv->sibur -= 1;
    server->clients[array_player[0]]->player->player_lvl = 4;
    server->clients[array_player[1]]->player->inv->linemate -= 2;
    server->clients[array_player[1]]->player->inv->phiras -= 2;
    server->clients[array_player[1]]->player->inv->sibur -= 1;
    server->clients[array_player[1]]->player->player_lvl = 4;
    return (true);
}
