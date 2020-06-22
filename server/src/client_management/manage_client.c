/*
** EPITECH PROJECT, 2020
** manage clients
** File description:
** zappy
*/

#include "server.h"

static int check_slots(server_t *server, char *team)
{
    for (int i = 0; server->teams[i] != NULL; i++)
        if (comp_teams(server, team, i))
            return(0);
    return (-1);
}

static team_t *append_client_to_array(team_t *team, client_t *client,
    char *team_name)
{
    int i = 0;

    client->team = team_name;
    if (team->clients == NULL) {
        team->clients = malloc(sizeof(client_t *) * 2);
        team->clients[0] = client;
        team->clients[1] = NULL;
        team->slots -= 1;
        return (team);
    }
    for (; team->clients[i] != NULL; i++);
    team->clients = realloc(team->clients, (sizeof(client_t *) * i + 1));
    team->clients[i] = client;
    team->clients[i + 1] = NULL;
    team->slots -= 1;
    return (team);
}

static team_t **add_client_to_team(char *team_name, team_t **team,
    client_t *client, server_t *server)
{
    for (int i = 0; team[i] != NULL; i++) {
        if (strcmp(team[i]->name, team_name) == 0) {
            client->player = init_new_player(server);
            team[i] = append_client_to_array(team[i],
                client, team_name);
            gettimeofday(&client->start_life, NULL);
            return (team);
        }
    }
    return (team);
}

static void send_new_player(server_t *server, client_t *client,
    client_t *clientai)
{
    if (client->player == NULL)
        dprintf(client->socket, "pnw #%d %d %d 0 %d %s\n",
            clientai->player->player_nb,
            clientai->player->x,
            clientai->player->y,
            clientai->player->player_lvl,
            clientai->team);
}

void move_client_to_team(char *team, server_t *server, client_t *client)
{
    
    if (check_slots(server, team) == -1) {
        dprintf(client->socket, "Not enough slots\n");
        server = remove_client(server, client);
        return;
    }
    server->teams = add_client_to_team(team, server->teams, client, server);
    dprintf(client->socket, "playerNumber: %d\n",
        client->player->player_nb);
    for (int i = 0; server->clients[i] != NULL; i++)
        send_new_player(server, server->clients[i], client);
}