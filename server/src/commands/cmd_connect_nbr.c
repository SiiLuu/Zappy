/*
** EPITECH PROJECT, 2020
** cmd_forward.c
** File description:
** zappy
*/

#include "server.h"

void cmd_connect_nbr(char *command, server_t *server, client_t *client)
{
    (void)command;
    if (time_handling(server, client, 0, NULL))
        return;
    for (int i = 0; server->teams[i] != NULL; i++)
        if (strcmp(server->teams[i]->name, client->team) == 0)
            dprintf(client->socket, "%d\n", server->teams[i]->slots);
}

static void remove_egg(server_t *server, int index)
{
    int nb_eggs = 0;

    for (; server->eggs[nb_eggs] != NULL; nb_eggs++);

    while (index + 1 < nb_eggs) {
        server->eggs[index] = server->eggs[index + 1];
        index++;
    }
    server->eggs = realloc(server->eggs, nb_eggs);
    server->eggs[nb_eggs - 1] = NULL;
}

static void add_slot(server_t *server, char *team)
{
    for (int i = 0; server->teams[i] != NULL; i++)
        if (strcmp(server->teams[i]->name, team) == 0)
            server->teams[i]->slots += 1;
}

void check_eggs(server_t *server)
{
    time_t actual_time = time(NULL);
    time_t diff = 0;

    if (server->eggs == NULL)
        return;
    for (int i = 0; server->eggs[i] != NULL; i++) {
        diff = actual_time - server->eggs[i]->time;
        if (diff >= (42 / server->freq)) {
            add_slot(server, server->eggs[i]->team);
            remove_egg(server, i);
        }
    }
}