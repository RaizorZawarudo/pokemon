/*
** EPITECH PROJECT, 2021
** B-CPE-210-BER-2-1-stumper4-eduard.popp
** File description:
** free_everything
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/helper.h"
#include "../include/my.h"

void output_error(char *message)
{
    int message_len = my_strlen(message);

    write(2, message, message_len);
}

void free_char_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

void free_parsed_csv(csv *parsed_csv)
{
    for (int i = 0; parsed_csv->labels[i]; i++)
        free(parsed_csv->labels[i]);
    for (int i = 0; parsed_csv->data[i]; i++)
        free(parsed_csv->data[i]);
    free(parsed_csv->labels);
    free(parsed_csv->data);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;

    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    memset(buffer, 0, sizeof(char) * (sb.st_size + 1));
    if (fd < 0) {
        output_error("File opening failed.\n");
        return NULL;
    }
    read(fd, buffer, sb.st_size);
    close(fd);
    return buffer;
}