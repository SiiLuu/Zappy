/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** test_priority
*/

#include <criterion/criterion.h>
#include "elevation.hpp"

Test(Redirector, find_simple_vision_level1_1)
{
    elevation elevation;
    Inventory::Food food;
    Inventory::Stones stones;
    std::vector<std::string> vision;

    vision.push_back("linemate");
    cr_assert_eq(elevation.compareLevelPriority(1, vision, stones, food), Inventory::resources::linemate);
}

Test(Redirector, find_simple_vision_level1_2)
{
    elevation elevation;
    Inventory::Food food;
    Inventory::Stones stones;
    std::vector<std::string> vision;

    vision.push_back("");
    cr_assert_eq(elevation.compareLevelPriority(1, vision, stones, food), Inventory::resources::none);
}

Test(Redirector, find_simple_vision_level3_food_critical)
{
    elevation elevation;
    Inventory::Food food;
    Inventory::Stones stones;
    std::vector<std::string> vision;

    food.setUnits(1);
    vision.push_back("");
    vision.push_back("linemate");
    vision.push_back("phiras");
    vision.push_back("sibur");
    vision.push_back("food");
    cr_assert_eq(elevation.compareLevelPriority(3, vision, stones, food), Inventory::resources::food);
}

Test(Redirector, find_simple_vision_level3_food_ok)
{
    elevation elevation;
    Inventory::Food food;
    Inventory::Stones stones;
    std::vector<std::string> vision;

    vision.push_back("");
    vision.push_back("");
    vision.push_back("food sibur phiras");
    vision.push_back("sibur");
    vision.push_back("food");
    cr_assert_eq(elevation.compareLevelPriority(3, vision, stones, food), Inventory::resources::phiras);
}

Test(Redirector, find_simple_vision_level2_food_warning)
{
    elevation elevation;
    Inventory::Food food;
    Inventory::Stones stones;
    std::vector<std::string> vision;

    food.removeUnits(700);
    vision.push_back("");
    vision.push_back("");
    vision.push_back("phiras");
    vision.push_back("phiras thystame");
    vision.push_back("phiras food");
    cr_assert_eq(elevation.compareLevelPriority(2, vision, stones, food), Inventory::resources::food);
}