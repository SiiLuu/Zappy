/*
** EPITECH PROJECT, 2020
** map.h
** File description:
** zappy project
*/

#ifndef MAP_H_
#define MAP_H_

typedef enum position_s
{
    NORTH,
    EAST,
    SOUTH,
    WEST
}position_t;

typedef struct tile_s
{
    int x;
    int y;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int food;

} tile_t;

typedef struct inventory_s
{
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;

} inventory_t;

typedef struct player_s
{
    int player_nb;
    int player_lvl;
    int x;
    int y;
    int food;
    position_t pos;
    inventory_t *inv;

}player_t;

typedef struct Object_s
{
    int tile_number;
    tile_t *tile;
} Object_t;

#endif /* !MAP_H_ */
