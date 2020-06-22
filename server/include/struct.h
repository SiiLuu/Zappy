/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** myteams
*/

#ifndef STRUCT_
#define STRUCT_

#include "map.h"
#include <sys/types.h>
#include <sys/time.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct object_types_s
{
    char *name;
    int type_nb;
} object_types_t;

typedef struct client_s
{
    int socket;
    long long time_to_do;
    struct timeval time_action_start;
    struct timeval start_life;
    struct timeval time_last_egg;
    bool egg_enable;
    bool action;
    bool ko_send;
    char *team;
    player_t *player;
} client_t;

typedef struct team_s
{
    int slots;
    char *name;
    client_t **clients;
} team_t;

typedef struct egg_s
{
    char *team;
    time_t time;
    int pos_x;
    int pos_y;
} egg_t;

typedef struct server_s
{
    int port;
    int width;
    int height;
    int clientNb;
    char **teams_name;
    int freq;
    int socket;
    fd_set *writefds;
    egg_t **eggs;
    team_t **teams;
    client_t **clients;
    Object_t *object;
} server_t;

typedef struct command_s
{
    char *name;
    void (*func)(char *, server_t *, client_t *);
} command_t;

#endif /* !STRUCT_ */
