/*
** EPITECH PROJECT, 2020
** cmd_fork.c
** File description:
** zappy
*/

#include "server.h"

static egg_t *init_new_egg(client_t *client)
{
    egg_t *new_egg = malloc(sizeof(egg_t));

    new_egg->team = client->team;
    new_egg->time = time(NULL);
    new_egg->pos_x = client->player->x;
    new_egg->pos_y = client->player->y;
    return (new_egg);
}

static void send_egg_pos(server_t *server, client_t *client)
{
    gettimeofday(&client->time_last_egg, NULL);
    client->egg_enable = true;
    dprintf(client->socket, "OK\n");
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player == NULL)
            dprintf(server->clients[i]->socket, "enw 1 %d %d %d\n",
                client->player->player_nb,
                client->player->x,
                client->player->y);
}

void cmd_fork(char *command, server_t *server, client_t *client)
{
    int i = 0;

    (void)command;
    if (time_handling(server, client, 42, "egg") ||
        is_slot_addable(server, client) == -1)
        return;
    if (egg_possible(server, client))
        return;
    if (server->eggs == NULL) {
        fill_eggs_struct(server, client);
        send_egg_pos(server, client);
        return;
    }
    for (; server->eggs[i] != NULL; i++);
    server->eggs = realloc(server->eggs, i + 2);
    server->eggs[i] = init_new_egg(client);
    server->eggs[i + 1] = NULL;
    send_egg_pos(server, client);
}