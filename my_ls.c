/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_ls
*/

#include "include/my_ls.h"
#include "include/struct.h"
#include "include/my_printf.h"

void my_ls_classic(char *dir)
{
    all_t classic;

    classic.dirp = opendir(dir);
    if (classic.dirp == NULL)
        exit (84);
    while ((classic.dp = readdir(classic.dirp)) != NULL) {
        if (classic.dp->d_name[0] != '.')
            my_printf(" %s", classic.dp->d_name);
    }
    my_putchar('\n');
    closedir(classic.dirp);
}

// void recursivity(all_t flagr)
// {
//     struct dirent *dp;
//     char *dir = flagr.dp->d_name;

//     dir[my_strlen(flagr.dp->d_name) +1] = '\0';
//     my_printf("%s\n", dir);
//     DIR *dirp = opendir(dir);
//     while ((dp = readdir(dirp)) != NULL) {
//         if (dp->d_name[0] != '.') {
//             stat(flagr.dp->d_name, &flagr.sts);
//             S_ISDIR(flagr.sts.st_mode) ? my_printf("\t%s\n", dp->d_name) : my_printf("\t%s :\n", dp->d_name);
//         }   
//     }
//     closedir(dirp);
// }


// void my_ls_r(char *dir)
// {
//     all_t flagr;

//     my_ls_classic(dir);
//     flagr.dirp = opendir(dir);
//     if (flagr.dirp == NULL)
//         exit (84);
//     my_putchar('\n');
//     while ((flagr.dp = readdir(flagr.dirp)) != NULL) {
//         if (flagr.dp->d_name[0] != '.') {
//             stat(flagr.dp->d_name, &flagr.sts);
//             S_ISDIR(flagr.sts.st_mode) ? recursivity(flagr) : NULL ;
//         }
//     }
//     closedir(flagr.dirp);
//     exit (0);
// }

void type(all_t flagl)
{
    if ((flagl.sts.st_mode & S_IFMT) == S_IFDIR) {
        my_putchar('d');
    }
    else if ((flagl.sts.st_mode & S_IFMT) == S_IFCHR) {
        my_putchar('c');
    }
    else if ((flagl.sts.st_mode & S_IFMT) == S_IFBLK) {
        my_putchar('b');
    } else
        my_putchar('-');
}

void get_perm(all_t flagl) 
{
    type(flagl);
    (flagl.sts.st_mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (flagl.sts.st_mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (flagl.sts.st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (flagl.sts.st_mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (flagl.sts.st_mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (flagl.sts.st_mode & S_IXGRP) ? my_putchar('x') : my_putchar('-');
    (flagl.sts.st_mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (flagl.sts.st_mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    if (flagl.sts.st_mode & S_ISVTX) {
        (flagl.sts.st_mode & S_IXOTH) ? my_putchar('t') : my_putchar('T');
    } else 
        (flagl.sts.st_mode & S_IXOTH) ? my_putchar('x') : my_putchar('-');
}

void my_ls_l(char *dir)
{
    all_t flagl;
    char *buff = malloc((sizeof(char) * 24) + 1);

    flagl.size = 0;
    flagl.dirp = opendir(dir);
    stat(dir, &flagl.sts);
    flagl.grp = getgrgid(flagl.sts.st_gid);
    flagl.usr = getpwuid(flagl.sts.st_uid);
    if (flagl.dirp == NULL) {
        exit (84);
    }
    flagl.size = get_total_block(flagl, dir);
    my_printf("total: %d\n", flagl.size);
    flagl.dirp = opendir(dir);
    while ((flagl.dp = readdir(flagl.dirp)) != NULL) {
        flagl.buff = flagl.dp->d_name;
        stat(flagl.buff, &flagl.sts);
        if (flagl.dp->d_name[0] != '.') {
            get_perm(flagl);
            buff = ctime(&flagl.sts.st_atime);
            flagl.buff = cut_time(buff);
            my_printf("%3d %s %s", flagl.sts.st_nlink, flagl.usr->pw_name, flagl.grp->gr_name);
            my_printf("\t%d\t%s %s\n", flagl.sts.st_size, my_strlowcase(flagl.buff), flagl.dp->d_name);
        }
    }
    closedir(flagl.dirp);
    exit (0);
}