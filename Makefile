##
## Makefile for dante in /home/lionel/Documents/delivery/PSU_2016_bstetris
## 
## Made by Lionell
## Login   <lionel.de-sousa@epitech.eu>
## 
## Started on  Wed May  3 15:40:46 2017 Lionell
## Last update Mon May 15 17:33:59 2017 Lionell
##

DEBUG	=	no

CC	=	gcc

NAME	=	depth/solver	\
		breadth/solver	\
		astar/solver	\
		tounament/solver	\
		mazes/generator	\
		generator/generator

NAME1	=	./depth/solver

NAME2   =	./generator/generator

NAME3	=	./astar/solver

NAME4	=	./breadth/solver

NAME5	=	./tournament/solver

NAME6	=	./mazes/generator

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

CPPFLAGS =	-Igenerator/include -Idepth/include

SRC	=	generator/src/laby.c	\
		generator/src/map.c	\
		generator/src/main.c	\
		generator/src/map_info.c	\
		generator/src/main_path.c	\
		generator/src/secondary_path.c	\
		depth/src/depth.c	\
		depth/src/main.c	\
		depth/src/read_file.c	\
		depth/src/my_str_to_word_tab.c

SRC1	=	generator/src/laby.c    \
                generator/src/map.c     \
                generator/src/map_info.c        \
                generator/src/main_path.c       \
                generator/src/secondary_path.c  \
		depth/src/depth.c	\
		depth/src/main.c	\
		depth/src/read_file.c	\
		depth/src/my_str_to_word_tab.c

SRC2	=	generator/src/laby.c    \
                generator/src/map.c     \
                generator/src/main.c    \
                generator/src/map_info.c        \
                generator/src/main_path.c       \
                generator/src/secondary_path.c  \

SRC3	=	generator/src/laby.c    \
                generator/src/map.c     \
                generator/src/main.c    \
                generator/src/map_info.c        \
                generator/src/main_path.c       \
                generator/src/secondary_path.c  \

SRC4   	=	generator/src/laby.c    \
                generator/src/map.c     \
                generator/src/main.c    \
                generator/src/map_info.c        \
                generator/src/main_path.c       \
                generator/src/secondary_path.c  \

SRC5    =	generator/src/laby.c    \
                generator/src/map.c     \
                generator/src/main.c    \
                generator/src/map_info.c        \
                generator/src/main_path.c       \
                generator/src/secondary_path.c  \

SRC6    =	generator/src/laby.c    \
                generator/src/map.c     \
                generator/src/main.c    \
                generator/src/map_info.c        \
                generator/src/main_path.c       \
                generator/src/secondary_path.c  \

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
