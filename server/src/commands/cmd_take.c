/*
** EPITECH PROJECT, 2020
** cmd_take.c
** File description:
** zappy
*/

#include "server.h"

static int check_other_objects(tile_t tile, int obj_type)
{
    switch (obj_type) {
        case 3:
            return (tile.mendiane);
            break;
        case 4:
            return (tile.phiras);
            break;
        case 5:
            return (tile.thystame);
            break;
        case 6:
            return (tile.food);
            break;
        default:
            return (-1);
    }
}

static int is_object_available(tile_t tile, char *object, int *obj_type)
{
    int nb = 0;

    for (int i = 0; i < OBJ_TYPES; i++)
        if (strcmp(object, object_types[i].name) == 0)
            *obj_type = object_types[i].type_nb;
    switch (*obj_type) {
        case 0:
            nb = tile.linemate;
            break;
        case 1:
            nb = tile.deraumere;
            break;
        case 2:
            nb = tile.sibur;
            break;
        default:
            nb = check_other_objects(tile, *obj_type);
            break;
    }
    return (nb);
}

static tile_t take_other_objects(tile_t tile, client_t *client, int obj_type)
{
    switch (obj_type) {
        case 4:
            tile.phiras -= 1;
            client->player->inv->phiras += 1;
            return (tile);
        case 5:
            tile.thystame -= 1;
            client->player->inv->thystame += 1;
            return (tile);
        case 6:
            tile.food -= 1;
            client->player->food += 1;
            return (tile);
        default:
            return (tile);
    }
    return (tile);
}

static tile_t take_object(tile_t tile, client_t *client, int obj_type)
{
    switch (obj_type) {
        case 0:
            tile.linemate -= 1;
            client->player->inv->linemate += 1;
            return (tile);
        case 1:
            tile.deraumere -= 1;
            client->player->inv->deraumere += 1;
            return (tile);
        case 2:
            tile.sibur -= 1;
            client->player->inv->sibur += 1;
            return (tile);
        case 3:
            tile.mendiane -= 1;
            client->player->inv->mendiane += 1;
            return (tile);
        default:
            return (take_other_objects(tile, client, obj_type));
    }
    return (tile);
}

void cmd_take_object(char *command, server_t *server, client_t *client)
{
    int i = 0;
    char **cmd_array = my_str_to_word_array(command, ' ');
    int pos = ((client->player->y) * server->width) + client->player->x;
    int obj_type = -1;

    if (time_handling(server, client, 7, NULL))
        return;
    for (i = 0; i < pos; i++);
    if (is_object_available(server->object->tile[i], cmd_array[1],
        &obj_type) > 0) {
        server->object->tile[i] = take_object(server->object->tile[i], client,
            obj_type);
        dprintf(client->socket, "OK\n");
        for (int i = 0; server->clients[i] != NULL; i++)
            send_bct(server, server->clients[i]);
    } else
        dprintf(client->socket, "KO\n");
}