/*
** EPITECH PROJECT, 2020
** tile_content command
** File description:
** zappy
*/

#include "server.h"

static int loop_object(server_t *server, char *first_arg, char *second_arg, int i)
{
    for (; i < server->object->tile_number; i++)
        if (server->object->tile[i].x == atoi(first_arg) &&
            server->object->tile[i].y == atoi(second_arg))
                return (i);
    return (0);
}

void tile_content(char *cmd, server_t *server, client_t *client)
{
    char *first_arg = get_arg(cmd, 1);
    char *second_arg = get_arg(cmd, 2);
    int i = 0;

    if (!is_a_number(first_arg) || !is_a_number(second_arg))
        dprintf(client->socket, "sbp");
    else {
        i = loop_object(server, first_arg, second_arg, i);
        dprintf(client->socket, "bct %d %d %d %d %d %d %d %d %d\n",
            server->object->tile[i].x, server->object->tile[i].y,
            server->object->tile[i].food, server->object->tile[i].linemate,
            server->object->tile[i].deraumere, server->object->tile[i].sibur,
            server->object->tile[i].mendiane, server->object->tile[i].phiras,
            server->object->tile[i].thystame);
    }
    free(first_arg);
    free(second_arg);
}