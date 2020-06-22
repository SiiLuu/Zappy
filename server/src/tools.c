/*
** EPITECH PROJECT, 2020
** tools.c
** File description:
** Zappy
*/

#include "server.h"

char *get_arg(char *cmd, int arg_nb)
{
    int i = 0;
    int k = 0;
    int space = -1;
    char *arg = malloc(sizeof(char) * 50);

    for (; cmd[i]; i++) {
        if (cmd[i] == ' ') {
            space++;
            for (; cmd[i] && cmd[i] == ' '; i++);
        }
        if (arg_nb - 1 == space) {
            for (; cmd[i] && cmd[i] != ' '; i++)
                arg[k++] = cmd[i];
            break;
        }
    }
    arg[k] = '\0';
    return (arg[0] == '\0' ? NULL : arg);
}

bool is_a_number(char *argv)
{
    if (argv == NULL)
        return (false);
    for (int i = 0; argv[i] != '\0'; i++) {
        if (isdigit(argv[i]) == 0)
            return (false);
    }
    return (true);
}

void life_management(struct timeval actual_time, server_t *server, int i)
{
    if (((actual_time.tv_sec) * 1000 + (actual_time.tv_usec) / 1000) >=
        ((server->clients[i]->time_action_start.tv_sec * 1000) +
        (server->clients[i]->time_action_start.tv_usec / 1000) +
        server->clients[i]->time_to_do)) {
            dprintf(server->clients[i]->socket, "KO\n");
            server->clients[i]->ko_send = false;
        }
}