/*
** EPITECH PROJECT, 2020
** helper.h
** File description:
** header file containing prototypes and definitions from all project files
*/

#ifndef HELPER_H_
#define HELPER_H_

typedef struct linked_list {
    char *name;
    struct linked_list *next;
    struct linked_list *prev;
    int atk;
    int def;
    int spd;
    int health;
    int size;
} llist_t;

typedef struct csv {
    char ***data;
    char **labels;
    int n_columns;
    int n_rows;
} csv;

typedef struct active_pokemon {
    char *name;
    int atk;
    int def;
    int spd;
    int health;
    int size;
} active_pokemon;

void swapper(llist_t *node1, llist_t *node2);
void swap_info(llist_t *node1, llist_t *node2);
void gameloop(llist_t *pokemons, char **av);
void sort_by_name(llist_t *pokemons);
char **my_str_to_word_array(char *str, char sep);
csv *parse_data(char *content, csv *output);
csv *parse_csv(char *filepath);
csv *parse_info(char *content);
void free_char_table(char **table);
void free_parsed_csv(csv *parsed_csv);
llist_t *create_list(void);
char *read_file(char *filepath);
llist_t *generate_mon_db(llist_t *list, csv *csv);
int new_node(llist_t *list, csv *csv, int i);
void sort_alpha(llist_t *pokemon);
void print_pokemon_list(llist_t *pokemons);

#endif /* !HELPER_H_ */
