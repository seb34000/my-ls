/*
** EPITECH PROJECT, 2020
** LS
** File description:
** main
*/

#include "include/my_ls.h"
#include "include/struct.h"
#include "include/my_printf.h"

void tcheck_arg(int argc, char *argv[], char *buff)
{
    if (argc == 1 || argv[1][0] != '-')
        my_ls_classic(buff);
    if (argc > 1 && argv[1][1] == 'l') {
        my_ls_l(buff);
    }
    if (argc > 1 && argv[1][1] == 'R') {
        my_ls_r(buff);
    }
}

int main(int argc, char **argv)
{
    char *dir = NULL;

    dir = get_file_to_str(dir, argv);
    tcheck_arg(argc, argv, dir);
}
