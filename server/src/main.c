/*
** EPITECH PROJECT, 2020
** Main file
** File description:
** myftp
*/

#include "server.h"


bool set_values(char *flags, server_t *server, char **argv, int count)
{
    if (strcmp(argv[count], flags) == 0) {
        if (!set_struct_value(flags, server, argv, count))
            return (false);
        return (true);
    }
    return (true);
}

bool check_good_flag(char **argv, char *av, server_t *server, int count)
{
    char *flags[6] = {"-p", "-x", "-y", "-n", "-c", "-f"};

    for (int i = 0; i < 6; i++) {
        if (!set_values(flags[i], server, argv, count))
            return (false);
    }
    return (true);
}

bool flags(char **argv, server_t *server, int i)
{
    if (argv[i][0] == '-') {
        if (!check_good_flag(argv, argv[i], server, i))
            return (true);
        return (false);
    }
    return (false);
}

bool is_wrong_parameters(int argc, char **argv, server_t *server)
{
    for (int i = 0; argv[i] != NULL; i++) {
        if (flags(argv, server, i))
            return (true);
    }
    if (server->port == 0)
        return (true);
    if (server->width == 0)
        return (true);
    if (server->height == 0)
        return (true);
    if (server->freq == 0)
        return (true);
    if (server->clientNb == 0)
        return (true);
    return (false);
}

int main(int argc, char **argv)
{
    server_t *server = malloc(sizeof(server_t));
    int server_socket = 0;
    int server_return_value = 0;

    init_struct_serv(server);
    if (is_wrong_parameters(argc, argv, server)) {
        printf("Error : wrong parameters.");
        return (ERROR);
    }
    init_struct_obj(server);
    server_socket = create_server(argv);
    if (server_socket == SOCKET_ERROR)
        return (ERROR);
    server->socket = server_socket;
    srand(time(NULL));
    server_return_value = server_loop(server);
    close(server_socket);
    return (server_return_value);
}