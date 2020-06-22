/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** test_inventory
*/

#include <criterion/criterion.h>
#include "inventory.hpp"

Test(Redirector, all_stones_getter_setter)
{
    Inventory::Stones stones;

    stones.setDeraumere(1);
    stones.setLinemate(2);
    stones.setMendiane(1);
    stones.setPhiras(3);
    stones.setSibur(1);
    stones.setThystame(4);
    cr_assert_eq(stones.getDeraumere(), 1);
    cr_assert_eq(stones.getLinemate(), 2);
    cr_assert_eq(stones.getMendiane(), 1);
    cr_assert_eq(stones.getPhiras(), 3);
    cr_assert_eq(stones.getSibur(), 1);
    cr_assert_eq(stones.getThystame(), 4);
}

Test(Redirector, all_food_getter_setter)
{
    Inventory::Food food;

    cr_assert_eq(food.getUnits(), 1260);
    food.setUnits(9);
    cr_assert_eq(food.getUnits(), 1134);
    cr_assert_eq(food.getStatus(), food.OK);
    food.removeUnits(600);
    cr_assert_eq(food.getStatus(), food.WARNING);
    food.removeUnits(500);
    cr_assert_eq(food.getStatus(), food.CRITICAL);
}

Test(Redirector, food_add_remove)
{
    Inventory::Food food;

    food.setUnits(9);
    food.addUnits(1);
    cr_assert_eq(food.getUnits(), 1260);
    food.removeUnits(10);
    cr_assert_eq(food.getUnits(), 1250);
}

Test(Redirector, Inventory_resources)
{
    std::vector<std::string> vision;

    vision.push_back("thystame food");
    vision.push_back("");
    vision.push_back("thystame");
    vision.push_back("phiras sibur");
    vision.push_back("");
    cr_assert_eq(Inventory::checkResources(1, vision), true);
    cr_assert_eq(Inventory::checkResources(3, vision), false);
}