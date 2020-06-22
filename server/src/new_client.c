/*
** EPITECH PROJECT, 2020
** new_client.c
** File description:
** myftp
*/

#include "server.h"

void send_info(client_t client_infos, server_t *server)
{
    dprintf(client_infos.socket, "msz %d %d\n", server->width, server->height);
}

static inventory_t *init_inventory()
{
    inventory_t *new_inv = malloc(sizeof(inventory_t));

    new_inv->deraumere = 0;
    new_inv->linemate = 0;
    new_inv->mendiane = 0;
    new_inv->phiras = 0;
    new_inv->sibur = 0;
    new_inv->thystame = 0;
    return (new_inv);
}

player_t *init_new_player(server_t *server)
{
    static int nb = 1;
    player_t *new_player = malloc(sizeof(player_t));

    new_player->x = random_number(server->width);
    new_player->y = random_number(server->height);
    new_player->inv = init_inventory();
    new_player->player_lvl = 1;
    new_player->player_nb = nb;
    new_player->pos = NORTH;
    new_player->food = 10;
    new_player->inv->deraumere = 0;
    new_player->inv->linemate = 0;
    new_player->inv->mendiane = 0;
    new_player->inv->phiras = 0;
    new_player->inv->sibur = 0;
    new_player->inv->thystame = 0;
    nb += 1;
    return (new_player);
}

client_t **add_client_list(client_t **clients, client_t client_infos,
    server_t *server)
{
    client_t *new_elem = malloc(sizeof(client_t));
    int i = 0;

    if (new_elem == NULL)
        return (clients);
    new_elem->socket = client_infos.socket;
    new_elem->ko_send = false;
    new_elem->team = "";
    new_elem->player = NULL;
    dprintf(client_infos.socket, "WELCOME\n");
    send_info(client_infos, server);
    if (clients[0] == NULL) {
        clients[0] = new_elem;
        clients[1] = NULL;
        return (clients);
    }
    for (; clients[i] != NULL; i++);
    clients[i] = new_elem;
    clients[i + 1] = NULL;
    return (clients);
}

void new_client_connected(server_t *server, int *fd_max)
{
    int csock = 0;
    static int nb = 2;
    struct sockaddr_in cin;
    client_t new_client;
    socklen_t len_cin = sizeof(cin);

    csock = accept(server->socket, (struct sockaddr *)&cin, &len_cin);
    printf("New connection from ip: %s, port: %d\n", \
    inet_ntoa(cin.sin_addr), ntohs(cin.sin_port));
    *fd_max += 1;
    new_client.socket = csock;
    if (server->clients == NULL) {
        server->clients = malloc(sizeof(client_t *) * nb);
        server->clients[0] = NULL;
    }
    else
        server->clients = realloc(server->clients, sizeof(client_t *) * nb);
    nb += 1;
    server->clients = add_client_list(server->clients, new_client, server);
}