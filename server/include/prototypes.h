/*
** EPITECH PROJECT, 2020
** prototypes.h
** File description:
** myteams
*/

#ifndef PROTOTYPES_
#define PROTOTYPES_

#include "map.h"
#include <stdbool.h>
#include <stdio.h>

int create_server(char **);
int server_loop(server_t *);
void new_client_connected(server_t *, int *);
void init_struct_obj(server_t *);
void set_teams_name(char **, int, server_t *);
void init_struct_serv(server_t *);
bool set_struct_value_3(char *, server_t *, char **, int);
bool set_struct_value_2(char *, server_t *, char **, int);
bool set_struct_value(char *, server_t *, char **, int);
void command_parser(char *, server_t *, client_t *);
int random_number(int max);
bool time_handling(server_t *, client_t *, int, const char *);
player_t *init_new_player(server_t *);
void check_eggs(server_t *);
void send_broad_pos(server_t *, client_t *);
bool egg_possible(server_t *, client_t *);
void fill_eggs_struct(server_t *, client_t *);
bool check_same_tile_team_level(server_t *, client_t *, int);
void cancel_broad(server_t *, client_t *);
void cancel_egg(server_t *, client_t *);
void cancel_inca(server_t *, client_t *);
bool comp_teams(server_t *, char *, int);

//Tools
char *get_arg(char *, int);
bool is_a_number(char *);
int opposite(int, int, int);

//utils
int *find_shortest_path(int *, int *, server_t *);
int *check_up(int *, int *, double *, server_t *);
int *check_down(int *, int *, double *, server_t *);
int *check_right(int *, int *, double *, server_t *);
int *check_left(int *, int *, double *, server_t *);
char *find_path(int *, int *, server_t *);
int is_slot_addable(server_t *server, client_t *);
char **my_str_to_word_array(char const *, char);

//manage client
server_t *remove_client(server_t *, client_t *);
void move_client_to_team(char *, server_t *, client_t *);
void is_team_existing(char *, server_t *, client_t *);

//commands graphical side
void map_content(char *, server_t *, client_t *);
void send_bct(server_t *, client_t *);
void map_size(char *, server_t *, client_t *);
void player_inventory(char *, server_t *, client_t *);
void player_level(char *, server_t *, client_t *);
void player_pos(char *, server_t *, client_t *);
void teams_name(char *, server_t *, client_t *);
void tile_content(char *, server_t *, client_t *);
void time_modif(char *, server_t *, client_t *);
void time_request(char *, server_t *, client_t *);

//commands client side
void cmd_forward(char *, server_t *, client_t *);
void cmd_right(char *, server_t *, client_t *);
void cmd_left(char *, server_t *, client_t *);
void cmd_look(char *, server_t *, client_t *);
void cmd_inventory(char *, server_t *, client_t *);
void cmd_broadcast(char *, server_t *, client_t *);
void cmd_connect_nbr(char *, server_t *, client_t *);
void cmd_fork(char *, server_t *, client_t *);
void cmd_eject(char *, server_t *, client_t *);
void cmd_take_object(char *, server_t *, client_t *);
void cmd_set_object(char *, server_t *, client_t *);
void life_management(struct timeval, server_t *, int);
void cmd_incantation(char *, server_t *, client_t *);
char *check_previous_and_next_tile_north(int *, char *, client_t *,
    server_t *);
char *check_previous_and_next_tile_east(int *, char *, client_t *,
    server_t *);
char *check_previous_and_next_tile_west(int *, char *, client_t *,
    server_t *);
char *check_previous_and_next_tile_south(int *, char *, client_t *,
    server_t *);
char *set_string(int, tile_t *, char *);

//server_disconnection.c
void update_server(server_t *, fd_set *, fd_set *);
void check_client_to_execute(server_t *, fd_set);
void disconnect_all_client(server_t *);

//elevation command
bool elevation_lvl_one(client_t *, int *);
bool elevation_lvl_two(server_t *, int *);
bool elevation_lvl_three(server_t *, int *);
bool elevation_lvl_four(server_t *, int *);
bool elevation_lvl_five(server_t *, int *);
bool elevation_lvl_six(server_t *, int *);
bool elevation_lvl_seven(server_t *, int *);

static const command_t command_array[] = {
    {"msz", &map_size},
    {"bct", &tile_content},
    {"mct", &map_content},
    {"tna", &teams_name},
    {"ppo", &player_pos},
    {"plv", &player_level},
    {"pin", &player_inventory},
    {"sgt", &time_request},
    {"sst", &time_modif},
    {"Forward", &cmd_forward},
    {"Right", &cmd_right},
    {"Left", &cmd_left},
    {"Look", &cmd_look},
    {"Inventory", &cmd_inventory},
    {"Broadcast", &cmd_broadcast},
    {"Connect_nbr", &cmd_connect_nbr},
    {"Fork", &cmd_fork},
    {"Eject", &cmd_eject},
    {"Take", &cmd_take_object},
    {"Set", &cmd_set_object},
    {"Incantation", &cmd_incantation}
};

static const object_types_t object_types[] = {
    {"linemate", 0},
    {"deraumere", 1},
    {"sibur", 2},
    {"mendiane", 3},
    {"phiras", 4},
    {"thystame", 5},
    {"food", 6}
};

#endif /* !PROTOTYPES_ */
