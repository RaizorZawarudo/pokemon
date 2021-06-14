/*
** EPITECH PROJECT, 2021
** B-CPE-210-BER-2-1-stumper4-eduard.popp
** File description:
** pokemons
*/

#include <dirent.h>
#include "../include/helper.h"
#include "../include/my.h"

void swap_info(llist_t *node1, llist_t *node2)
{
    node1->name = node2->name;
    node1->atk = node2->atk;
    node1->def = node2->def;
    node1->spd = node2->spd;
    node1->health = node2->health;
}

void swapper(llist_t *node1, llist_t *node2)
{
    llist_t *tempvar = malloc(sizeof(llist_t));

    tempvar->name = node1->name;
    tempvar->atk = node1->atk;
    tempvar->def = node1->def;
    tempvar->spd = node1->spd;
    tempvar->health = node1->health;
    swap_info(node1, node2);
    node2->name = tempvar->name;
    node2->atk = tempvar->atk;
    node2->def = tempvar->def;
    node2->spd = tempvar->spd;
    node2->health = tempvar->health;
    free(tempvar);
}


void sort_by_name(llist_t *pokemons)
{
    llist_t *temp1 = NULL;
    llist_t *temp2 = NULL;
    char *temp1name = NULL;
    char *temp2name = NULL;

    for (int i = pokemons->size - 2; i >= 0; i--) {
        temp1 = pokemons->prev;
        temp2 = temp1->next;
        for (int j = 0; j <= i; j++) {
            temp1name = my_strlowcase(temp1->name);
            temp2name = my_strlowcase(temp2->name);
            if (strcmp(temp1name, temp2name) > 0)
                swapper(temp1, temp2);
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
}

void print_pokemon_list(llist_t *pokemons)
{
    for (pokemons = pokemons->prev; pokemons != NULL; pokemons = pokemons->next) {
        my_printf("Pokemon %s has %d attack, %d defense, %d speed and %d health", pokemons->name, pokemons->atk, pokemons->def, pokemons->spd, pokemons->health);
        my_putchar('\n');
    }
}