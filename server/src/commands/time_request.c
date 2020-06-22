/*
** EPITECH PROJECT, 2020
** time_request command
** File description:
** Zappy
*/

#include "server.h"

void time_request(char *cmd, server_t *server, client_t *client)
{
    (void)server;
    dprintf(client->socket, "%s\n", cmd);
}