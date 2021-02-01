/*
** EPITECH PROJECT, 2020
** LS
** File description:
** my_strislower
*/

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] > 64 && str[i] < 91) {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
