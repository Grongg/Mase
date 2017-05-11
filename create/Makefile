##
## Makefile for navy in /home/zirk/Epitech/PSU_2016_navy/bonus
## 
## Made by Zirk
## Login   <zirk@epitech.net>
## 
## Started on  Fri Feb 10 13:24:51 2017 Zirk
## Last update Sat Apr 29 16:42:41 2017 Zirk
##

DEBUG	= yes

CC	= gcc

NAME	= dante

CFLAGS = -Wall -Wextra

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

CPPFLAGS = -Iinclude

SRCS	= src/main.c \
	  src/map.c \
	  src/laby.c \
	  src/map_info.c \
	  src/main_path.c \
	  src/secondary_path.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
	@ echo "\033[0;32m--------------------------------------------\033[0m"
	@ echo "\033[0;32m|                                          |\033[0m"
	@ echo "\033[0;32m|      Program succesfully compiled !      |\033[0m"
	@ echo "\033[0;32m|                                          |\033[0m"
	@ echo "\033[0;32m--------------------------------------------\033[0m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
