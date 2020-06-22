/*
** EPITECH PROJECT, 2020
** player_position command
** File description:
** Zappy
*/

#include "server.h"

void player_pos(char *cmd, server_t *server, client_t *client)
{
    int k = 0;
    int i = 0;
    char *first_arg = get_arg(cmd, 1);
    char *player_nb = malloc(sizeof(char) * strlen(first_arg) - 1);

    (void)server;
    if (first_arg[0] == '#') {
        for (int i = 1; first_arg[i]; i++)
            player_nb[k++] = first_arg[i];
        player_nb[k] = '\0';
    }
    else
        dprintf(client->socket, "sbp");
    dprintf(client->socket, "ppo %d %d %d %d\n",
        client->player->player_nb, client->player->x,
        client->player->y, client->player->pos);
    free(first_arg);
    free(player_nb);
}