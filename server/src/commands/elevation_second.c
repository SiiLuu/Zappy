/*
** EPITECH PROJECT, 2020
** elevation_second.c
** File description:
** elevation_second.c
*/

#include "server.h"

bool elevation_lvl_four(server_t *server, int *array_player)
{
    int size = 0;

    for (; array_player[size] != -1; size++);
    if (size < 4)
        return (false);
    for (int i = 0; array_player[i] != -1; i++) {
        if (server->clients[array_player[i]]->player->inv->linemate < 1
            || server->clients[array_player[i]]->player->inv->deraumere < 1
            || server->clients[array_player[i]]->player->inv->sibur < 2
            || server->clients[array_player[i]]->player->inv->phiras < 1)
            return (false);
    }
    for (int i = 0; array_player[i] != -1; i++) {
        server->clients[array_player[i]]->player->inv->linemate -= 1;
        server->clients[array_player[i]]->player->inv->deraumere -= 1;
        server->clients[array_player[i]]->player->inv->sibur -= 2;
        server->clients[array_player[i]]->player->inv->phiras -= 1;
    }
    return (true);
}

bool elevation_lvl_five(server_t *server, int *array_player)
{
    int size = 0;

    for (; array_player[size] != -1; size++);
    if (size < 4)
        return (false);
    for (int i = 0; array_player[i] != -1; i++) {
        if (server->clients[array_player[i]]->player->inv->linemate < 1
            || server->clients[array_player[i]]->player->inv->deraumere < 2
            || server->clients[array_player[i]]->player->inv->sibur < 1
            || server->clients[array_player[i]]->player->inv->mendiane < 3)
            return (false);
    }
    for (int i = 0; array_player[i] != -1; i++) {
        server->clients[array_player[i]]->player->inv->linemate -= 1;
        server->clients[array_player[i]]->player->inv->deraumere -= 2;
        server->clients[array_player[i]]->player->inv->sibur -= 1;
        server->clients[array_player[i]]->player->inv->mendiane -= 3;
    }
    return (true);
}

bool elevation_lvl_six(server_t *server, int *array_player)
{
    int size = 0;

    for (; array_player[size] != -1; size++);
    if (size < 6)
        return (false);
    for (int i = 0; array_player[i] != -1; i++) {
        if (server->clients[array_player[i]]->player->inv->linemate < 1
            || server->clients[array_player[i]]->player->inv->deraumere < 2
            || server->clients[array_player[i]]->player->inv->sibur < 3
            || server->clients[array_player[i]]->player->inv->phiras < 1)
            return (false);
    }
    for (int i = 0; array_player[i] != -1; i++) {
        server->clients[array_player[i]]->player->inv->linemate -= 1;
        server->clients[array_player[i]]->player->inv->deraumere -= 2;
        server->clients[array_player[i]]->player->inv->sibur -= 3;
        server->clients[array_player[i]]->player->inv->phiras -= 1;
    }
    return (true);
}

void use_ressources(server_t *server, int *array_player,
    int i)
{
    server->clients[array_player[i]]->player->inv->linemate -= 2;
    server->clients[array_player[i]]->player->inv->deraumere -= 2;
    server->clients[array_player[i]]->player->inv->sibur -= 2;
    server->clients[array_player[i]]->player->inv->mendiane -= 2;
    server->clients[array_player[i]]->player->inv->phiras -= 2;
    server->clients[array_player[i]]->player->inv->thystame -= 1;
}

bool elevation_lvl_seven(server_t *server, int *array_player)
{
    int size = 0;
    int i = 0;

    for (; array_player[size] != -1; size++);
    if (size < 6)
        return (false);
    for (; array_player[i] != -1; i++) {
        if (server->clients[array_player[i]]->player->inv->linemate < 2
            || server->clients[array_player[i]]->player->inv->deraumere < 2
            || server->clients[array_player[i]]->player->inv->sibur < 2
            || server->clients[array_player[i]]->player->inv->mendiane < 2
            || server->clients[array_player[i]]->player->inv->phiras < 2
            || server->clients[array_player[i]]->player->inv->thystame < 1)
            return (false);
        else
            use_ressources(server, array_player, i);
    }
    return (true);
}