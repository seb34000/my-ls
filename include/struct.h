/*
** EPITECH PROJECT, 2020
** LS
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_


#include <sys/cdefs.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>

typedef struct all_s {
   struct passwd *usr;
   struct dirent *dp;
   struct stat sts;
   struct group *grp;
   mode_t perm;
   DIR *dirp;
   char *buff;
   int size;
} all_t;

#endif /* !STRUCT_H_ */
