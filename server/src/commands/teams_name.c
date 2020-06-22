/*
** EPITECH PROJECT, 2020
** team_name command
** File description:
** zappy
*/

#include "server.h"

void send_broad_pos(server_t *server, client_t *client)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player == NULL)
            dprintf(server->clients[i]->socket, "pbc %d message\n",
                client->player->player_nb);
}

void teams_name(char *cmd, server_t *server, client_t *client)
{
    (void)cmd;
    for (int i = 0; server->teams_name[i] != NULL; i++)
        dprintf(client->socket, "tna %s\n", server->teams_name[i]);
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player != NULL)
            dprintf(client->socket, "pnw #%d %d %d 0 %d %s\n",
                server->clients[i]->player->player_nb,
                server->clients[i]->player->x,
                server->clients[i]->player->y,
                server->clients[i]->player->player_lvl,
                server->clients[i]->team);
}