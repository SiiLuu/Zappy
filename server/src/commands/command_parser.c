/*
** EPITECH PROJECT, 2020
** command_parser.c
** File description:
** zappy
*/

#include "server.h"

void command_parser(char *command, server_t *server, client_t *client)
{
    char **cmd_array = my_str_to_word_array(command, ' ');
    printf("%d ! %s\n",
        (client->player == NULL) ? 0 : client->player->player_nb, command);

    if (cmd_array == NULL || strcmp(command, "\n") == 0) {
        dprintf(client->socket, "KO\n");
        return;
    }
    for (int i = 0; i < CMD_NBR; i++) {
        if (strcmp(cmd_array[0], command_array[i].name) == 0) {
            command_array[i].func(command, server, client);
            return;
        }
    }
    if (strncmp(command, "teamName:", 9) != 0) {
        dprintf(client->socket, "KO\n");
        return ;
    }
    is_team_existing(cmd_array[1], server, client);
}