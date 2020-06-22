/*
** EPITECH PROJECT, 2020
** Main file
** File description:
** myftp
*/

#include "server.h"

static team_t *add_team(char *team_name)
{
    team_t *new_team = malloc(sizeof(team_t));

    new_team->name = team_name;
    new_team->clients = NULL;
    new_team->slots = 1;
    return (new_team);
}

void set_teams_name(char **argv, int i, server_t *server)
{
    int k = 0;
    int j = 0;

    for (; argv[j] != NULL && argv[j][0] != '-'; j++);
    server->teams_name = malloc(sizeof(char *) * (j + 2));
    for (; argv[i] != NULL && argv[i][0] != '-'; i++) {
        server->teams_name[k] = malloc(sizeof(char) * strlen(argv[i]) + 1);
        strcpy(server->teams_name[k], argv[i]);
        k++;
    }
    server->teams_name[k] = NULL;
    server->teams = malloc(sizeof(team_t *) * (k + 1));
    for (int i = 0; server->teams_name[i] != NULL; i++)
        server->teams[i] = add_team(server->teams_name[i]);
}

bool set_struct_value_3(char *flag, server_t *server, char **argv, int i)
{
    if (strcmp(flag, "-f") == 0) {
        if (!is_a_number(argv[i + 1]))
            return (false);
        server->freq = atoi(argv[i + 1]);
    }
    else  if (strcmp(flag, "-n") == 0) {
        if (argv[i + 1][0] == '-')
            return (false);
        set_teams_name(argv, i + 1, server);
    }
    else
        return (false);
    return (true);
}

bool set_struct_value_2(char *flag, server_t *server, char **argv, int i)
{
    if (strcmp(flag, "-y") == 0) {
        if (!is_a_number(argv[i + 1]))
            return (false);
        server->height = atoi(argv[i + 1]);
    }
    else  if (strcmp(flag, "-c") == 0) {
        if (!is_a_number(argv[i + 1]))
            return (false);
        server->clientNb = atoi(argv[i + 1]);
    }
    else {
        if (!set_struct_value_3(flag, server, argv, i))
            return (false);
    }
    return (true);
}

bool set_struct_value(char *flag, server_t *server, char **argv, int i)
{
    if (strcmp(flag, "-p") == 0) {
        if (!is_a_number(argv[i + 1]))
            return (false);
        server->port = atoi(argv[i + 1]);
    }
    else if (strcmp(flag, "-x") == 0) {
        if (!is_a_number(argv[i + 1]))
            return (false);
        server->width = atoi(argv[i + 1]);
    }
    else {
        if (!set_struct_value_2(flag, server, argv, i))
            return (false);
    }
    return (true);
}