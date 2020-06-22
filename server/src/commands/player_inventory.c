/*
** EPITECH PROJECT, 2020
** player_inventory command
** File description:
** Zappy
*/

#include "server.h"

void player_inventory(char *cmd , server_t *server, client_t *client)
{
    (void)cmd;
    (void)server;
    dprintf(client->socket, "pin %d %d %d %d %d %d %d %d %d %d\n",
        client->player->player_nb,
        client->player->x,
        client->player->y,
        client->player->food,
        client->player->inv->linemate,
        client->player->inv->deraumere,
        client->player->inv->sibur,
        client->player->inv->mendiane,
        client->player->inv->phiras,
        client->player->inv->thystame);
}