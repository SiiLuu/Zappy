/*
** EPITECH PROJECT, 2020
** initiate_server.c
** File description:
** myteams
*/

#include "server.h"

void init_struct_serv(server_t *server)
{
    server->object = malloc(sizeof(Object_t));
    server->eggs = NULL;
    server->clientNb = 0;
    server->freq = 0;
    server->port = 0;
    server->height = 0;
    server->width = 0;
    server->teams_name = NULL;
    server->clients = NULL;
}

int random_number(int max)
{
    return((rand() % max));
}

void init_struct_tile(server_t *server)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (i < server->object->tile_number) {
        if (x >= server->width) {
            x = 0;
            y++;
        }
        server->object->tile[i].x = x;
        server->object->tile[i].y = y;
        server->object->tile[i].food = rand() % 3;
        server->object->tile[i].linemate = rand() % 3;
        server->object->tile[i].deraumere = rand() % 3;
        server->object->tile[i].mendiane = rand() % 3;
        server->object->tile[i].phiras = rand() % 3;
        server->object->tile[i].sibur = rand() % 3;
        server->object->tile[i].thystame = rand() % 2;
        x++;
        i++;
    }
}

void init_struct_obj(server_t *server)
{
    server->object->tile = malloc(sizeof(tile_t) *
        (server->width * server->height));
    server->object->tile_number = server->width * server->height;
    init_struct_tile(server);
}

server_t *initiate_server(void)
{
    server_t *server = malloc(sizeof(server_t));

    if (server == NULL)
        return (NULL);
    return (server);
}
