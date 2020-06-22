/*
** EPITECH PROJECT, 2020
** cmd_forward.c
** File description:
** zappy
*/

#include "server.h"

static void send_player_pos(server_t *server, client_t *client,
    client_t *clientai)
{
    if (client->player == NULL)
        dprintf(client->socket, "ppo %d %d %d %d\n",
            clientai->player->player_nb,
            clientai->player->x,
            clientai->player->y,
            clientai->player->player_lvl);
}

static team_t *update_client_pos(team_t *team, client_t *client,
    int axe, int x_or_y)
{
    for (int i = 0; team->clients && team->clients[i] != NULL; i++) {
        if (client->socket == team->clients[i]->socket && x_or_y == 0) {
            team->clients[i]->player->x = axe;
            return (team);
        } else if (client->socket == team->clients[i]->socket &&
            x_or_y == 1) {
            team->clients[i]->player->y = axe;
            return (team);
        }
    }
    return (team);
}

static void is_leaving_the_map(server_t *server, client_t *client, int orient,
    int x_or_y)
{
    int axe = 0;

    if (x_or_y == 0) {
        axe = client->player->x + orient;
        if (axe >= server->width)
            axe = 0;
        else if (axe < 0)
            axe = server->width - 1;
        client->player->x = axe;
    } else {
        axe = client->player->y + orient;
        if (axe >= server->height)
            axe = 0;
        else if (axe < 0)
            axe = server->height - 1;
        client->player->y = axe ;
    }
    for (int i = 0; server->teams[i] != NULL; i++) {
        server->teams[i] = update_client_pos(server->teams[i], client, axe,
            x_or_y);
    }
}

void cmd_forward(char *command, server_t *server, client_t *client)
{
    (void)command;
    if (time_handling(server, client, 7, NULL))
        return;
    switch (client->player->pos) {
        case NORTH:
                is_leaving_the_map(server, client, -1, 1);
            break;
        case EAST:
                is_leaving_the_map(server, client, 1, 0);
            break;
        case WEST:
                is_leaving_the_map(server, client, -1, 0);
            break;
        case SOUTH:
                is_leaving_the_map(server, client, 1, 1);
            break;
    }
    dprintf(client->socket, "OK\n");
    for (int i = 0; server->clients[i] != NULL; i++)
        send_player_pos(server, server->clients[i], client);
}