/*
** EPITECH PROJECT, 2020
** cmd_forward.c
** File description:
** zappy
*/

#include "server.h"

void send_or_not(server_t *server, client_t *client, const char *animation)
{
    static bool broadcast = false;
    static bool egg = false;
    static bool incantation = false;

    (animation != NULL && strcmp(animation, "broadcast") == 0) ?
        broadcast = true : (0);
    (animation != NULL && strcmp(animation, "egg") == 0) ? egg = true : (0);
    (animation != NULL && strcmp(animation, "incantation") == 0) ?
        incantation = true : (0);
    if (broadcast == true && animation == NULL) {
        cancel_broad(server, client);
        broadcast = false;
    }
    if (egg == true && animation == NULL) {
        cancel_egg(server, client);
        egg = false;
    }
    if (incantation == true && animation == NULL) {
        cancel_inca(server, client);
        incantation = false;
    }
}

bool time_handling(server_t *server, client_t *client, int duration,
    const char *animation)
{
    struct timeval actual_time;

    gettimeofday(&actual_time, NULL);
    if (client->action) {
        if (((actual_time.tv_sec) * 1000 + (actual_time.tv_usec) / 1000) >=
            ((client->time_action_start.tv_sec * 1000) +
            (client->time_action_start.tv_usec / 1000) + client->time_to_do)) {
            send_or_not(server, client, animation);
            client->time_to_do = (duration / server->freq) * 1000;
            client->action = true;
            gettimeofday(&client->time_action_start, NULL);
            return (false);
        }
        client->ko_send = true;
        return (true);
    }
    send_or_not(server, client, animation);
    client->time_to_do = (duration / server->freq) * 1000;
    client->action = true;
    gettimeofday(&client->time_action_start, NULL);
    return (false);
}

void cmd_inventory(char *command, server_t *server, client_t *client)
{
    (void)command;
    if (time_handling(server, client, 1, NULL))
        return;
    dprintf(client->socket, "food %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystame %d,\n",
        client->player->food,
        client->player->inv->linemate,
        client->player->inv->deraumere,
        client->player->inv->sibur,
        client->player->inv->mendiane,
        client->player->inv->phiras,
        client->player->inv->thystame);
}