/*
** EPITECH PROJECT, 2020
** cmd_eject.c
** File description:
** zappy
*/

#include "server.h"

void fill_eggs_struct(server_t *server, client_t *client)
{
    server->eggs = malloc(sizeof(egg_t *) * 2);
    server->eggs[0] = malloc(sizeof(egg_t));
    server->eggs[0]->team = client->team;
    server->eggs[0]->time = time(NULL);
    server->eggs[0]->pos_x = client->player->x;
    server->eggs[0]->pos_y = client->player->y;
    server->eggs[1] = NULL;
}

bool egg_possible(server_t *server, client_t *client)
{
    struct timeval actual_time;

    gettimeofday(&actual_time,  NULL);
    if (((actual_time.tv_sec) * 1000 + (actual_time.tv_usec) / 1000) >=
        ((client->time_last_egg.tv_sec * 1000) +(client->time_last_egg.tv_usec
        / 1000) + (((600 + 42) / server->freq) * 1000)))
        client->egg_enable = false;
    else
        dprintf(client->socket, "KO\n");
    return (client->egg_enable);
}

void cmd_eject(char *command, server_t *server, client_t *client)
{
    (void)command;
    if (time_handling(server, client, 7, NULL))
        return;
    dprintf(client->socket, "OK\n");
}

bool check_same_tile_team_level(server_t *server, client_t *client, int i)
{
    if (strcmp(server->clients[i]->team, client->team) == 0
        && client->player->player_lvl == server->clients[i]->player->player_lvl
        && server->clients[i]->player->x == client->player->x
        && server->clients[i]->player->y == client->player->y)
        return (true);
    return (false);
}