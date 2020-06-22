/*
** EPITECH PROJECT, 2020
** map_content.c
** File description:
** zappy
*/

#include "server.h"

void map_content(char *cmd, server_t *server, client_t *client)
{
    (void)cmd;
    for (int i = 0; i < server->object->tile_number; i++) {
        dprintf(client->socket, "bct %d %d %d %d %d %d %d %d %d\n",
            server->object->tile[i].x, server->object->tile[i].y,
            server->object->tile[i].food, server->object->tile[i].linemate,
            server->object->tile[i].deraumere, server->object->tile[i].sibur,
            server->object->tile[i].mendiane, server->object->tile[i].phiras,
            server->object->tile[i].thystame);
    }
}

void send_bct(server_t *server, client_t *client)
{
    if (client->player == NULL)
        for (int i = 0; i < server->object->tile_number; i++)
            dprintf(client->socket, "bct %d %d %d %d %d %d %d %d %d\n",
                server->object->tile[i].x, server->object->tile[i].y,
                server->object->tile[i].food, server->object->tile[i].linemate,
                server->object->tile[i].deraumere, server->object->tile[i].sibur,
                server->object->tile[i].mendiane, server->object->tile[i].phiras,
                server->object->tile[i].thystame);
}
