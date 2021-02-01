##
## EPITECH PROJECT, 2020
## MAkefile
## File description:
##  cp the libmy.a into lib/, then cp the my.h into include/, then clean the temp files
##

RM	=	rm -f

CC	=	gcc

AR	=	ar

CFLAGS	=	-w -Wall -Wextra -Werror
CPPFLAGS	=	-Iinclude

SRC		=	./get_files.c \
			./my_ls.c \
			./main.c \
			./my_ls_r.c

SRC1	=	$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

LIB	=	lib/my/libmy.a lib/my_printf/libmy.a

TARGET	=	my_ls

SRC2	=	$(wildcard lib/my_printf/*.c)

MAIN	=	my_ls.c

all:	$(TARGET)

$(TARGET):	$(LIB)
	$(CC) $(CFLAGS) $(SRC) $(LIB) $(SRC1) $(SRC2) -o my_ls -Llib/ -lmy
#	$(CC) $(CFLAGS) $(SRC1) -o $@ $(CPPFLAGS) $(LIB) -Llib/ -lmy

$(LIB):	$(OBJ)
	$(AR) rsc $@ $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *.o
	$(RM) *~

fclean:	clean
	$(RM) $(LIB)
	$(RM) $(TARGET)

re:	fclean all