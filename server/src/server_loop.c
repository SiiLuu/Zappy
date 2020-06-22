/*
** EPITECH PROJECT, 2020
** server_loop
** File description:
** myftp
*/

#include "server.h"

volatile bool is_loop = true;

void signal_handler(int signal_num)
{
    (void)signal_num;
    is_loop = false;
}

static void send_death_pos(server_t *server, client_t *client)
{
    for (int i = 0; server->clients[i] != NULL; i++)
        if (server->clients[i]->player == NULL)
            dprintf(server->clients[i]->socket, "pdi %d\n",
                client->player->player_nb);
}

void decrement(server_t *server, client_t *client, struct timeval actual_time)
{
    if (client->player != NULL && client->player->food > 0)
        if (((actual_time.tv_sec) * 1000 + (actual_time.tv_usec) / 1000) >=
            ((client->start_life.tv_sec * 1000) +
            (client->start_life.tv_usec / 1000) + (126 / server->freq) * 1000)) {
            client->player->food--;
            gettimeofday(&client->start_life, NULL);
            if (client->player->food <= 0) {
                dprintf(client->socket, "dead\n");
                send_death_pos(server, client);
            }
        }
}

void decrement_life(server_t *server)
{
    struct timeval actual_time;

    gettimeofday(&actual_time, NULL);
    for (int i = 0; server->clients[i] != NULL; i++) {
        if (server->clients[i]->player != NULL &&
            server->clients[i]->player->food > 0)
            decrement(server, server->clients[i], actual_time);
        if (server->clients[i]->player != NULL &&
            server->clients[i]->ko_send) {
            life_management(actual_time, server, i);
        }
    }
}

int server_loop(server_t *server)
{
    fd_set readfds;
    fd_set writefds;
    int fd_max = server->socket + 1;

    signal(SIGINT, signal_handler);
    server->writefds = &writefds;
    while (is_loop) {
        update_server(server, &readfds, &writefds);
        if (select(fd_max, &readfds, &writefds, NULL , NULL) == SOCKET_ERROR)
            return (CORRECT);
        if (FD_ISSET(server->socket, &readfds))
            new_client_connected(server, &fd_max);
        check_client_to_execute(server, readfds);
        decrement_life(server);
        check_eggs(server);
    }
    printf("Closing the server ...\n");
    disconnect_all_client(server);
    return (CORRECT);
}
