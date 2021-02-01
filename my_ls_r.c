/*
** EPITECH PROJECT, 2020
** LS
** File description:
** my_ls_r
*/

#include "include/my_ls.h"
#include "include/struct.h"
#include "include/my_printf.h"

void recursivity(all_t flagr)
{
    struct dirent *dp;
    char *dir = flagr.dp->d_name;

    dir[my_strlen(flagr.dp->d_name) +1] = '\0';
    my_printf("%s\n", dir);
    DIR *dirp = opendir(dir);
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            stat(flagr.dp->d_name, &flagr.sts);
            S_ISDIR(flagr.sts.st_mode) ? my_printf("\t%s\n", dp->d_name) : my_printf("\t%s :\n", dp->d_name);
        }   
    }
    closedir(dirp);
}


void my_ls_r(char *dir)
{
    all_t flagr;

    my_ls_classic(dir);
    flagr.dirp = opendir(dir);
    if (flagr.dirp == NULL)
        exit (84);
    my_putchar('\n');
    while ((flagr.dp = readdir(flagr.dirp)) != NULL) {
        if (flagr.dp->d_name[0] != '.') {
            stat(flagr.dp->d_name, &flagr.sts);
            S_ISDIR(flagr.sts.st_mode) ? recursivity(flagr) : NULL ;
        }
    }
    closedir(flagr.dirp);
    exit (0);
}