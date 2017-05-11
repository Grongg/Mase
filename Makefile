##
## Makefile for dante in /home/lionel/Documents/delivery/PSU_2016_bstetris
## 
## Made by Lionell
## Login   <lionel.de-sousa@epitech.eu>
## 
## Started on  Wed May  3 15:40:46 2017 Lionell
## Last update Wed May  3 21:09:42 2017 Lionell
##

DEBUG	=	yes

CC	=	gcc

NAME	=	depth	\
		generator	\
		astar	\
		breadth	\
		tournement	\
		mazes

NAME1	=	depth

NAME2   =	generator

NAME3	=	astar

NAME4	=	breadth

NAME5	=	tournement

NAME6	=	mazes

ifeq ($(DEBUG),yes)

#CFLAGS += -ansi -pedantic
CFLAGS += -std=c99
CFLAGS += -Wmissing-prototypes -Wfloat-equal -Wstrict-prototypes -Wshadow -Winit-self -Wcast-align
CFLAGS += -Waggregate-return
CFLAGS += -Wunreachable-code -Wlogical-op -Wdisabled-optimization
CFLAGS += -fstrict-overflow -Wstrict-overflow=4
CFLAGS += -fstack-protector-strong -Wstack-protector
CFLAGS += -g3 -O0

else

CFLAGS += -Werror

endif

CPPFLAGS =	-Icreate/include -Isolver/include

#SRC doit contenir tout je dis bien tout les .c et les autres .c mis dans les src1, src2, etc ... sont juste pour te montrer que cela fonctionne voila voila

SRC	=	create/src/laby.c	\
		create/src/map.c	\
		create/src/main.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c	\
		solver/src/depth.c	\
		solver/src/main.c	\
		solver/src/read_file.c	\
		solver/src/my_str_to_word_tab.c

SRC1	=	create/src/laby.c	\
		create/src/map.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c	\
		solver/src/depth.c	\
		solver/src/main.c	\
		solver/src/read_file.c	\
		solver/src/my_str_to_word_tab.c

SRC2	=	create/src/laby.c	\
		create/src/map.c	\
		create/src/main.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c

SRC3	=	create/src/laby.c	\
		create/src/map.c	\
		create/src/main.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c

SRC4   	=	create/src/laby.c	\
		create/src/map.c	\
		create/src/main.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c

SRC5    =	create/src/laby.c	\
		create/src/map.c	\
		create/src/main.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c

SRC6    =	create/src/laby.c	\
		create/src/map.c	\
		create/src/main.c	\
		create/src/map_info.c	\
		create/src/main_path.c	\
		create/src/secondary_path.c

OBJS	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME1) $(SRC1) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	$(CC) -o $(NAME3) $(SRC3) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	$(CC) -o $(NAME4) $(SRC4) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	$(CC) -o $(NAME5) $(SRC5) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	$(CC) -o $(NAME6) $(SRC6) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	@ echo "\033[0;32m--------------------------------------------\033[0m"
	@ echo "\033[0;32m|                                          |\033[0m"
	@ echo "\033[0;32m|      Program succesfully compiled !      |\033[0m"
	@ echo "\033[0;32m|                                          |\033[0m"
	@ echo "\033[0;32m--------------------------------------------\033[0m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) $(NAME3)
	$(RM) $(NAME4)
	$(RM) $(NAME5)
	$(RM) $(NAME6)

re:	fclean all

.PHONY:	all clean fclean re
