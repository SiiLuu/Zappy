/*
** EPITECH PROJECT, 2020
** check_teams
** File description:
** zappy
*/

#include "server.h"

server_t *remove_client(server_t *server, client_t *client)
{
    int i = 0;
    int nb_player = 0;

    for (; server->clients[nb_player] != NULL; nb_player++);
    for (; server->clients[i] != NULL; i++)
        if (server->clients[i]->socket == client->socket)
            break;
    while (i + 1 < nb_player) {
        server->clients[i] = server->clients[i + 1];
        i++;
    }
    server->clients = realloc(server->clients, nb_player);
    server->clients[nb_player - 1] = NULL;
    return (server);
}

void is_team_existing(char *team, server_t *server, client_t *client)
{
    if (strncmp(team, "GRAPHIC", 8) == 0)
        return;
    for (int i = 0; server->teams_name[i] != NULL; i++) {
        if (strcmp(team, server->teams_name[i]) == 0) {
            move_client_to_team(team, server, client);
            return;
        }
    }
    server = remove_client(server, client);
}

bool comp_teams(server_t *server, char *team, int i)
{
    if (strcmp(team, server->teams[i]->name) == 0)
        if (server->teams[i]->slots > 0)
            return(true);
    return (false);
}