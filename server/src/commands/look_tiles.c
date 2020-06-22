/*
** EPITECH PROJECT, 2020
** look_tiles
** File description:
** zappy
*/

#include "server.h"

char *set_string(int i,  tile_t *tile, char *tiles)
{
    (tile[i].linemate > 0) ? strcat(tiles, "linemate ") : (0);
    (tile[i].deraumere > 0) ? strcat(tiles, "deraumere ") : (0);
    (tile[i].sibur > 0) ? strcat(tiles, "sibur ") : (0);
    (tile[i].mendiane > 0) ? strcat(tiles, "mendiane ") : (0);
    (tile[i].phiras > 0) ? strcat(tiles, "phiras ") : (0);
    (tile[i].thystame > 0) ? strcat(tiles, "thystame ") : (0);
    (tile[i].food > 0) ? strcat(tiles, "food ") : (0);
    strcat(tiles, ", ");
    return (tiles);
}

char *check_previous_and_next_tile_north(int *pos, char *tiles,
    client_t *client, server_t *server)
{
    if (pos[0] < 0) {
        pos[0] += (server->width * server->height);
    } else if ((server->object->tile[pos[0]].y + client->player->player_lvl !=
            client->player->y) &&
            (server->object->tile[pos[0] + pos[1]].x == 0)) {
        pos[0] += server->width;
    } else if ((server->object->tile[pos[0]].y + client->player->player_lvl !=
        client->player->y) &&
        (server->object->tile[pos[0] - pos[1]].x == server->width - 1)) {
        pos[0] -= server->width;
    }
    tiles = set_string(pos[0], server->object->tile, tiles);
    return (tiles);
}

char *check_previous_and_next_tile_east(int *pos, char *tiles,
    client_t *client, server_t *server)
{
    if (pos[0] < 0)
        pos[0] += (server->width * server->height);
    else if (pos[0] > (server->width * server->height) - 1) {
        pos[0] -= (server->width * server->height);
    } else if (server->object->tile[pos[0]].x - client->player->player_lvl !=
        client->player->x)
        pos[0] -= server->width;
    tiles = set_string(pos[0], server->object->tile, tiles);
    return (tiles);
}

char *check_previous_and_next_tile_west(int *pos, char *tiles,
    client_t *client, server_t *server)
{
    if (pos[0] < 0)
        pos[0] += (server->width * server->height);
    else if (pos[0] > (server->width * server->height) - 1) {
        pos[0] -= (server->width * server->height);
    } else if (server->object->tile[pos[0]].x + client->player->player_lvl !=
        client->player->x)
        pos[0] += server->width;
    tiles = set_string(pos[0], server->object->tile, tiles);
    return (tiles);
}

char *check_previous_and_next_tile_south(int *pos, char *tiles,
    client_t *client, server_t *server)
{
    if (pos[0] > (server->width * server->height) - 1) {
        pos[0] -= (server->width * server->height);
    } else if ((server->object->tile[pos[0]].y - client->player->player_lvl !=
            client->player->y) &&
            (server->object->tile[pos[0] + pos[1]].x == 0)) {
        pos[0] += server->width;
    } else if ((server->object->tile[pos[0]].y - client->player->player_lvl !=
        client->player->y) &&
        (server->object->tile[pos[0] - pos[1]].x == server->width - 1)) {
        pos[0] -= server->width;
    }
    tiles = set_string(pos[0], server->object->tile, tiles);
    return (tiles);
}