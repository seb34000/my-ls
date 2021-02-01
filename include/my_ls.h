/*
** EPITECH PROJECT, 2020
** LS
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

//#include <_types.h>
#include <sys/cdefs.h>
//#include <Availability.h>
//#include <sys/_types/_size_t.h>
//#include <sys/_types/_null.h>
//#include <sys/_types/_s_ifmt.h>
#include <dirent.h>
#include <sys/stat.h>
//#include <sys/_types.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
#include <sys/types.h>
#include <pwd.h>
//#include <uuid/uuid.h>
#include <grp.h>
#include <errno.h>
#include "my_printf.h"

//best printf ever
//void my_printf(char *str, ...);

//for total first line ls -l
int tcheck_size_all(struct dirent *dp, struct stat sts, int *fd);

//open_files
int fs_open_file_no_str(char const *filepath);

//get filephath
char *get_file_to_str(char *buff, char *argv[]);

int get_total_block(all_t flagl, char *dir);

char *cut_time(char *buff);

char *my_strcpy(char *dest, char const *src);
//int my_strlen(char const *str);
char *my_strlowcase(char *str);

#endif /* !MY_LS_H_ */
