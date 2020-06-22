/*
** EPITECH PROJECT, 2020
** cmd_look.c
** File description:
** zappy
*/

#include "server.h"

char *look_north(server_t *server, client_t *client)
{
    int pos = 0;
    int i = 0;
    char *tiles = malloc(sizeof(char) * 500);
    int cases[2] = {0, 0};

    for (; i < server->object->tile_number; i++)
        if (server->object->tile[i].x == client->player->x &&
        server->object->tile[i].y == client->player->y)
            break;
    tiles = set_string(i, server->object->tile, tiles);
    for (int k = 1; k <= client->player->player_lvl; k++) {
        pos = i - (server->width * k);
        for (int i = pos - k; i <= pos + k; i++) {
            cases[0] = i;
            cases[1] = k;
            tiles = check_previous_and_next_tile_north(cases, tiles, client,
                server);
        }
    }
    return (tiles);
}

char *look_east(server_t *server, client_t *client)
{
    int pos = 0;
    int i = 0;
    char *tiles = malloc(sizeof(char) * 500);
    int cases[2] = {0, 0};

    for (; i < server->object->tile_number; i++)
        if (server->object->tile[i].x == client->player->x &&
        server->object->tile[i].y == client->player->y)
            break;
    tiles = set_string(i, server->object->tile, tiles);
    for (int k = 1; k <= client->player->player_lvl; k++) {
        pos = i + k;
        for (int i = pos - (k * server->width); i <= pos + (k * server->width);
            i += server->width) {
            cases[0] = i;
            cases[1] = k;
            tiles = check_previous_and_next_tile_east(cases, tiles, client,
                server);
        }
    }
    return (tiles);
}

char *look_west(server_t *server, client_t *client)
{
    int pos = 0;
    int i = 0;
    char *tiles = malloc(sizeof(char) * 500);
    int cases[2] = {0, 0};

    for (; i < server->object->tile_number; i++)
        if (server->object->tile[i].x == client->player->x &&
        server->object->tile[i].y == client->player->y)
            break;
    tiles = set_string(i, server->object->tile, tiles);
    for (int k = 1; k <= client->player->player_lvl; k++) {
        pos = i - k;
        for (int i = pos + (k * server->width); i >= pos - (k * server->width);
            i -= server->width) {
            cases[0] = i;
            cases[1] = k;
            tiles = check_previous_and_next_tile_west(cases, tiles, client,
                server);
        }
    }
    return (tiles);
}

char *look_south(server_t *server, client_t *client)
{
    int pos = 0;
    int i = 0;
    char *tiles = malloc(sizeof(char) * 500);
    int cases[2] = {0, 0};

    for (; i < server->object->tile_number; i++)
        if (server->object->tile[i].x == client->player->x &&
        server->object->tile[i].y == client->player->y)
            break;
    tiles = set_string(i, server->object->tile, tiles);
    for (int k = 1; k <= client->player->player_lvl; k++) {
        pos = i + (server->width * k);
        for (int i = pos - k; i <= pos + k; i++) {
            cases[0] = i;
            cases[1] = k;
            tiles = check_previous_and_next_tile_west(cases, tiles, client,
                server);
        }
    }
    return (tiles);
}

void cmd_look(char *command, server_t *server, client_t *client)
{
    int i = 0;
    char *tiles = NULL;
    (void)command;

    if (time_handling(server, client, 7, NULL))
        return;
    if (client->player->pos == NORTH) {
        tiles = look_north(server, client);
        dprintf(client->socket, "%s\n", tiles);
    } else if (client->player->pos == EAST) {
        tiles = look_east(server, client);
        dprintf(client->socket, "%s\n", tiles);
    } else if (client->player->pos == WEST) {
        tiles = look_west(server, client);
        dprintf(client->socket, "%s\n", tiles);
    } else if (client->player->pos == SOUTH) {
        tiles = look_south(server, client);
        dprintf(client->socket, "%s\n", tiles);
    } else
        dprintf(client->socket, "KO\n");
    free(tiles);
}