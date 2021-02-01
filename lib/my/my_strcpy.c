/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** my_strcpy
*/

#include "my_ls.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int size = my_strlen(src);

    while (size > i) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}