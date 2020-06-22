/*
** EPITECH PROJECT, 2020
** cmd_right.c
** File description:
** zappy
*/

#include "server.h"

void cmd_right(char *command, server_t *server, client_t *client)
{
    (void)command;
    if (time_handling(server, client, 7, NULL))
        return;
    if (client->player->pos == 3) {
        client->player->pos = 0;
    } else
        client->player->pos += 1;
    dprintf(client->socket, "OK\n");
}