/*
** EPITECH PROJECT, 2020
** LS
** File description:
** get_files
*/

#include "include/my_ls.h"``
#include <stdio.h>
#include <stdlib.h>
#include "include/struct.h"
#include <dirent.h>

char *get_file_to_str(char *buff, char *argv[])
{
    char *buff_test = NULL;

    for (int i = 1; argv[i]; i++) {
        if (argv[i][0] != '-') {
            buff = malloc((sizeof(char) + (my_strlen(argv[i]))+ 1));
            buff[my_strlen(argv[i]) + 1] = '\0';
            for (int j = 0; argv[i][j]; j++) {
                buff[j] = argv[i][j];
            }
        } 
    }
    if (buff == NULL) {
        buff_test = malloc((sizeof(char) * 2) + 1);
        buff_test = "./";
        return (buff_test);
    } else
        return (buff);
}

int get_total_block(all_t flagl, char *dir)
{
    while ((flagl.dp = readdir(flagl.dirp)) != NULL) {

        //test
        if (flagl.dp->d_name[0] != '.') {
            flagl.buff = flagl.dp->d_name;
            stat(flagl.buff, &flagl.sts);
            flagl.size += flagl.sts.st_blocks;
        }
    }
    closedir(flagl.dirp);
    return (flagl.size);
}

char *cut_time(char *buff)
{
    char *buffer = malloc((sizeof(char) * 13));

    buffer[0] = buff[8];
    buffer[1] = buff[9];
    buffer[2] = ' ';
    buffer[3] = buff[4];
    buffer[4] = buff[5];
    buffer[5] = buff[6];
    buffer[6] = ' ';
    buffer[7] = buff[11];
    buffer[8] = buff[12];
    buffer[9] = ':';
    buffer[10] = buff[14];
    buffer[11] = buff[15];
    buffer[12] = '\0';

    return (buffer);
}