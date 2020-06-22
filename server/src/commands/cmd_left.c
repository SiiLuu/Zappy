/*
** EPITECH PROJECT, 2020
** cmd_left.c
** File description:
** zappy
*/

#include "server.h"

void cancel_inca(server_t *server, client_t *client)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player == NULL)
            dprintf(server->clients[i]->socket, "pie %d %d 0\n",
                client->player->x,
                client->player->y);
}

void cancel_egg(server_t *server, client_t *client)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player == NULL)
            dprintf(server->clients[i]->socket, "eht %d %d\n",
            client->player->x,
            client->player->y);
}

void cancel_broad(server_t *server, client_t *client)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player == NULL)
            dprintf(server->clients[i]->socket, "pbc %d message\n",
                client->player->player_nb);
}

void cmd_left(char *command, server_t *server, client_t *client)
{
    (void)command;
    if (time_handling(server, client, 7, NULL))
        return;
    if (client->player->pos == 0) {
        client->player->pos = 3;
    } else
        client->player->pos -= 1;
    dprintf(client->socket, "OK\n");
}