/*
** EPITECH PROJECT, 2020
** path_finding.c
** File description:
** path_finding.c
*/

#include "server.h"

int opposite(int x_or_y, int researcher, int search)
{
    int res = x_or_y / 2 / 2;

    if (res > search && res < researcher)
        return (1);
    if (res > researcher && res < search)
        return (2);
    return (0);
}

int *check_down(int *researcher, int *search, double *shortest,
    server_t *server)
{
    int *result = malloc(sizeof(int) * 2);
    int res = 0;

    if (opposite(server->width, researcher[0], search[0]) == 1) {
        res = server->width - researcher[0];
        res += sqrt(square(0 - search[0]) + \
            square(researcher[1] - search[1]));
        if (res < *shortest) {
            result[0] = researcher[0] + 1;
            result[1] = researcher[1];
            *shortest = res;
        }
    }
    return (result);
}

int *check_up(int *researcher, int *search, double *shortest,
    server_t *server)
{
    int *result = malloc(sizeof(int) * 2);
    int res = 0;

    if (opposite(server->width, researcher[0], search[0]) == 2) {
        res = researcher[0];
        res += sqrt(square(server->width - search[0]) + \
            square(researcher[1] - search[1]));
        if (res < *shortest) {
            result[0] = researcher[0] - 1;
            result[1] = researcher[1];
            *shortest = res;
        }
    }
    return (result);
}

int *check_right(int *researcher, int *search, double *shortest,
    server_t *server)
{
    int *result = malloc(sizeof(int) * 2);
    int res = 0;

    if (opposite(server->height, researcher[1], search[1]) == 1) {
        res = server->height - researcher[1];
        res += sqrt(square(researcher[0] - search[0]) + square(0 - search[1]));
        if (res < *shortest) {
            result[0] = researcher[0];
            result[1] = researcher[1] + 1;
            *shortest = res;
        }
    }
    return (result);
}

int *check_left(int *researcher, int *search, double *shortest,
    server_t *server)
{
    int *result = malloc(sizeof(int) * 2);
    int res = 0;

    if (opposite(server->height, researcher[1], search[1]) == 2) {
        res = researcher[1];
        res += sqrt(square(researcher[0] - search[0]) + \
            square(server->height - search[1]));
        if (res < *shortest) {
            result[0] = researcher[0];
            result[1] = researcher[1] - 1;
            *shortest = res;
        }
    }
    return (result);
}