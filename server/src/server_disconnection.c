/*
** EPITECH PROJECT, 2020
** server_disconntection
** File description:
** zappy
*/

#include "server.h"

void disconnect_all_client(server_t *server)
{
    for (int i = 0; server->clients[i] != NULL; i++) {
        dprintf(server->clients[i]->socket, "disconnect\n");
    }
}

char *get_message(int from)
{
    int status = 0;
    char *message = calloc(MAX_BUFFER, MAX_BUFFER);

    if (message == NULL)
        return (NULL);
    status = read(from, message, MAX_BUFFER);
    if (status <= 0)
        return (NULL);
    return (message);
}

void update_server(server_t *server, fd_set *readfds, fd_set *writefds)
{
    FD_ZERO(readfds);
    FD_ZERO(writefds);
    FD_SET(server->socket, readfds);
    FD_SET(server->socket, writefds);
    if (server->clients == NULL)
        return;
    for (int i = 0; server->clients[i] != NULL; i++) {
        if (server->clients[i] != NULL && server->clients[i]->socket != -1) {
            FD_SET(server->clients[i]->socket, readfds);
            FD_SET(server->clients[i]->socket, writefds);
        }
    }
}

int parse_command(char *message, server_t *server, int i, fd_set readfds)
{
    if (FD_ISSET(server->clients[i]->socket, &readfds)) {
        message = get_message(server->clients[i]->socket);
        if (message != NULL) {
            command_parser(message, server, server->clients[i]);
            return (0);
        }
    }
}

void check_client_to_execute(server_t *server, fd_set readfds)
{
    char *message = NULL;

    for (int i = 0; server->clients[i] != NULL; i++) {
        parse_command(message, server, i, readfds);
    }
}