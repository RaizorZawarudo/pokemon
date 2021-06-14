/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <time.h>
#include <dirent.h>
#include "../include/helper.h"
#include "../include/my.h"

void check_each_pokemon(int first, int second, char **av)
{
    if (first != 1)
        printf("%s does not exist in the pokedex\n", av[1]);
    if (second != 1)
        printf("%s does not exist in the pokedex\n", av[2]);
}

int check_arguments(int ac, char **av, llist_t *pokemons)
{
    int first_arg_true = 0;
    int second_arg_true = 0;
    llist_t *current = pokemons->prev;
    if (ac != 3)
        return 0;
    for (; current!= NULL; current = current->next) {
        if (!strcmp(av[1], current->name)) {
            first_arg_true = 1;
        }
        if (!strcmp(av[2], current->name))
            second_arg_true = 1;
    }
    check_each_pokemon(first_arg_true, second_arg_true, av);  
    if (first_arg_true != 1 || second_arg_true != 1)
        return 0;        
    return 1;
}

char *make_relative(char *path, char *file)
{
    int i = 0;
    char *relative = malloc(sizeof(char) * (8 + strlen(file)));

    for (; i < 8 ; i++)
        relative[i] = path[i];
    for (int j = 0; file[j] != '\0'; j++) {
        relative[i] = file[j];
        i++;
    }
    return relative;
}

int create_pokemon_database(llist_t *pokemons, csv *parsed_csv, char *pokfolder)
{
    DIR *folder;
    struct dirent *entry;
    char *relative = NULL;

    folder = opendir(pokfolder);
    if (folder == NULL) {
        perror("Unable to read directory");
        return(1);
    }
    while( (entry = readdir(folder)) ) {
        if (!strcmp (entry->d_name, ".")) continue;
        if (!strcmp (entry->d_name, "..")) continue;
        relative = make_relative("pokecfg/", entry->d_name);  
        parsed_csv = parse_csv(relative);
        generate_mon_db(pokemons, parsed_csv);
        free(relative);
        free_parsed_csv(parsed_csv);
    }
    closedir(folder);
    return(0);
}

int main(int ac, char **av)
{
    llist_t *pokemons = create_list();
    csv *parsed_csv = malloc(sizeof(csv));

    srand(time(NULL));
    if (pokemons == NULL)
        return 0;
    if (parsed_csv == NULL)
        return 0;    
    create_pokemon_database(pokemons, parsed_csv, "pokecfg");
    if (!check_arguments(ac, av, pokemons))
        return (0);
    //sort_by_name(pokemons);  
    print_pokemon_list(pokemons);
    gameloop(pokemons, av);
    return 0;
}