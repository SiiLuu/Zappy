/*
** EPITECH PROJECT, 2020
** time_modif command
** File description:
** Zappy
*/

#include "server.h"

void time_modif(char *cmd, server_t *server, client_t *client)
{
    (void)server;
    dprintf(client->socket, "%s\n", cmd);
}