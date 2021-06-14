/*
** EPITECH PROJECT, 2021
** pokemon
** File description:
** gameloop
*/

#include <time.h>
#include "../include/helper.h"
#include "../include/my.h"

void copy_data(llist_t *pok1, llist_t *pok2, llist_t *pokemons, char **av)
{
    llist_t *current = pokemons->prev;
    for (; current != NULL; current = current->next) {
        if (!strcmp(av[1], current->name)) {
            pok1->name = current->name;
            pok1->health = current->health;
            pok1->atk = current->atk;
            pok1->def = current->def;
            pok1->spd = current->spd;
        }
        if (!strcmp(av[2], current->name)) {
            pok2->name = current->name;
            pok2->health = current->health;
            pok2->atk = current->atk;
            pok2->def = current->def;
            pok2->spd = current->spd;
        }
    }
}

int end_fight(llist_t *pok1, llist_t *pok2)
{
    if (pok1->health <= 0) {
        printf("%s is KO\n", pok1->name);
        printf("%s wins the fight!\n", pok2->name);
        return 1;
    }
    if (pok2->health <= 0) {
        printf("%s is KO\n", pok2->name);
        printf("%s wins the fight!\n", pok1->name);
        return 1;
    }
    return 0;
}

void attack_cycle(llist_t *pok1, llist_t *pok2)
{
    int damage = rand() % (pok1->atk + 1);
    int damage_dealt = 0;

    if (damage > pok2->def) {
        damage_dealt = damage - pok2->def;
        pok2->health = pok2->health - damage_dealt;
    }
    else
        damage_dealt = 0;
    printf("%s attacks for %d damage\n", pok1->name, damage);
    printf("%s blocks %d damage\n",pok2->name, pok2->def);

    if (pok2->health < 0)
        pok2->health = 0;
    printf("%s loses %d health (%d left)\n", pok2->name, damage_dealt,
    pok2->health);
}

void gameloop(llist_t *pokemons, char **av)
{
    int gameover = 0;
    llist_t *pok1 = malloc(sizeof(llist_t));
    llist_t *pok2 = malloc(sizeof(llist_t));

    copy_data(pok1, pok2, pokemons, av);
    if (pok2->spd > pok1->spd)
        swapper(pok1, pok2);
    while (gameover == 0) {
        attack_cycle(pok1, pok2);
        gameover = end_fight(pok1, pok2);
        if (gameover == 0) {
            attack_cycle(pok2, pok1);
            gameover = end_fight(pok1, pok2);
        }
    }
    free(pok1);
    free(pok2);
}