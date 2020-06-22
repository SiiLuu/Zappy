/*
** EPITECH PROJECT, 2020
** cmd_fork.c
** File description:
** zappy
*/

#include "server.h"

int is_slot_addable(server_t *server, client_t *client)
{
    int nb_clients = 0;
    team_t *act_team = NULL;

    for (int i = 0; server->teams[i] != NULL; i++) {
        if (strcmp(server->teams[i]->name, client->team) == 0) {
            act_team = server->teams[i];
            break;
        }
    }
    for (; act_team->clients[nb_clients] != NULL; nb_clients++);
    if (nb_clients < server->clientNb)
        return (0);
    dprintf(client->socket, "KO\n");
    return (-1);
}