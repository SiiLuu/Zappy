/*
** EPITECH PROJECT, 2020
** map_size command
** File description:
** zappy
*/

#include "server.h"

void map_size(char *cmd, server_t *server, client_t *client)
{
    (void)cmd;
    dprintf(client->socket, "msz %d %d\n", server->width, server->height);
}