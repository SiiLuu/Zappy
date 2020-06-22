/*
** EPITECH PROJECT, 2020
** cmd_broadcast.c
** File description:
** zappy
*/

#include "server.h"

int *find_shortest_path(int *researcher, int *search, server_t *server)
{
    int *result = NULL;
    double shortest = DBL_MAX;

    result = check_up(researcher, search, &shortest, server);
    result = check_down(researcher, search, &shortest, server);
    result = check_left(researcher, search, &shortest, server);
    result = check_right(researcher, search, &shortest, server);
    if (sqrt(square(researcher[0] - search[0]) + square(researcher[1] -
        search[1])) < shortest) {
        result[0] = search[0];
        result[1] = search[1];
    }
    return (result);
}

char *find_path(int *researcher, int *search, server_t *server)
{
    int *shortest_point = find_shortest_path(researcher, search, server);

    if (researcher[0] > shortest_point[0])
        return ("UP");
    if (researcher[0] < shortest_point[0])
        return ("DOWN");
    if (researcher[1] > shortest_point[1])
        return ("LEFT");
    if (researcher[1] < shortest_point[1])
        return ("RIGHT");
    return ("ERROR");
}

static char *concat_broadcast_info(char **message, client_t *r_client,
    client_t *s_client, server_t *server)
{
    int *researcher = malloc(sizeof(int) * 2);
    int *search = malloc(sizeof(int) * 2);
    char *ret = message[1];

    researcher[0] = r_client->player->x;
    researcher[1] = r_client->player->y;
    search[0] = s_client->player->x;
    search[1] = s_client->player->y;
    strcat(ret, message[2]);
    strcat(ret, " ");
    strcat(ret, find_path(researcher, search, server));
    free(researcher);
    free(search);
    return (ret);
}

static void browse_teams(char **message, client_t *client, server_t *server,
    team_t *team)
{
    char *str = NULL;

    for (int i = 0; team->clients && team->clients[i] != NULL; i++) {
        str = concat_broadcast_info(message, client, team->clients[i], \
            server);
        if (team->clients[i]->socket != client->socket)
            dprintf(client->socket, "%s\n", str);
        memset(str, 0, sizeof(str));
    }
}

void cmd_broadcast(char *command, server_t *server, client_t *client)
{
    char **cmd_array = my_str_to_word_array(command, ' ');

    if (time_handling(server, client, 7, "broadcast"))
        return;
    for (int i = 0; server->teams[i] != NULL; i++) {
        browse_teams(cmd_array, client, server, server->teams[i]);
    }
    dprintf(client->socket, "OK\n");
    send_broad_pos(server, client);
}