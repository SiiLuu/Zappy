/*
** EPITECH PROJECT, 2020
** Player_level command
** File description:
** Zappy
*/

#include "server.h"

void player_level(char *cmd, server_t *server, client_t *client)
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
    for (; client->player->player_nb != atoi(player_nb); i++);

    dprintf(client->socket, "plv %d %d\n", client->player->player_nb,
        client->player->player_lvl);

    free(first_arg);
    free(player_nb);
}