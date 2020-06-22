/*
** EPITECH PROJECT, 2020
** cmd_incantation.c
** File description:
** zappy
*/

#include "server.h"

int *find_player_same_tile_team_level(server_t *server, client_t *client)
{
    int size = 1;
    int *array_player = malloc(sizeof(int) * size);
    int pos = 1;

    for (int i = 0; server->clients[i] != NULL; i++) {
        if (server->clients[i]->player == NULL)
            continue;
        if (server->clients[i]->player->player_nb ==
            client->player->player_nb) {
            array_player[0] = i;
            size++;
            continue;
        }
        if (check_same_tile_team_level(server, client, i)) {
            array_player = realloc(array_player, (sizeof(int) * (++size)));
            array_player[pos] = i;
            pos++;
        }
    }
    array_player[(size - 1)] = -1;
    return (array_player);
}

bool wich_incantation(server_t *server, client_t *client, int *array_player)
{
    switch (client->player->player_lvl) {
        case 1:
            return (elevation_lvl_one(client, array_player));
        case 2:
            return (elevation_lvl_two(server, array_player));
        case 3:
            return (elevation_lvl_three(server, array_player));
        case 4:
            return (elevation_lvl_four(server, array_player));
        case 5:
            return (elevation_lvl_five(server, array_player));
        case 6:
            return (elevation_lvl_six(server, array_player));
        case 7:
            return (elevation_lvl_seven(server, array_player));
        default:
            return (false);
    }
    return (false);
}

static void send_inc_pos(server_t *server, client_t *client,
    client_t *clientai)
{
    if (client->player == NULL)
        dprintf(client->socket, "pic %d %d %d\n",
            clientai->player->x,
            clientai->player->y,
            clientai->player->player_lvl);
}

bool time_inc_handling(server_t *server, int *array_player)
{
    for (int i = 0; array_player[i] != -1; i++)
        if (time_handling(server, server->clients[array_player[i]], 5,
            "incantation"))
            return (true);
    return (false);
}

void cmd_incantation(char *command, server_t *server, client_t *client)
{
    bool check_action = false;
    int i = 0;
    char **cmd_array = my_str_to_word_array(command, ' ');
    int pos = ((client->player->y) * server->width) + client->player->x;
    int *array_player = find_player_same_tile_team_level(server, client);

    for (int i = 0; array_player[i] != -1; i++)
        if (server->clients[array_player[i]]->action == true)
            check_action = true;
    if (wich_incantation(server, client, array_player) && check_action) {
        if (time_inc_handling(server, array_player))
            return;
        dprintf(client->socket, "%d\n", client->player->player_lvl);
        for (int i = 0; server->clients[i] != NULL; i++)
            send_inc_pos(server, server->clients[i], client);
    }
    else {
        dprintf(client->socket, "KO\n");
    }
}