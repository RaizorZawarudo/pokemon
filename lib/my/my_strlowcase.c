/*
** EPITECH PROJECT, 2020
** 20my_strlowcase.c
** File description:
** .
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *my_strlowcase(char *str)
{
    char *new_str = strdup(str);
    int i = 0;

    while (new_str[i] != '\0') {
        if (new_str[i] >= 'A' && new_str[i] <= 'Z') {
            new_str[i] += 'a' - 'A';
        }
        i++;
    }
    return (new_str);
}
