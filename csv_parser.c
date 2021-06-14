/*
** EPITECH PROJECT, 2021
** csv_parser.c
** File description:
** Prototypes in parsing.h
*/

#include <stdlib.h>
#include "my.h"
#include "helper.h"

csv *parse_info(char *content)
{
    int comma_count = 0;
    int i;
    csv *output = malloc(sizeof(csv));
    char **content_lines = NULL;

    if (!content || !output)
        return NULL;
    for (i = 0; content[i] && content[i] != '\n'; i++)
        comma_count = (content[i] == ';') ? comma_count + 1 : comma_count;
    content_lines = my_str_to_word_array(content, '\n');
    for (i = 0; content_lines[i]; i++);
    output->n_rows = i - 1;
    output->n_columns = comma_count + 1;
    output->labels = my_str_to_word_array(content_lines[0], ';');
    free_char_table(content_lines);
    return output;
}

csv *parse_data(char *content, csv *output)
{
    char **content_lines = my_str_to_word_array(content, '\n');

    output->data = malloc(sizeof(char **) * (output->n_rows + 1));
    for (int i = 1; content_lines[i]; i++)
        output->data[i - 1] = my_str_to_word_array(content_lines[i], ';');
    output->data[output->n_rows] = NULL;
    free_char_table(content_lines);
    return output;
}

csv *parse_csv(char *filepath)
{
    char *content = read_file(filepath);
    csv *output = parse_info(content);

    if (!output)
        return NULL;
    output = parse_data(content, output);
    return output;
}