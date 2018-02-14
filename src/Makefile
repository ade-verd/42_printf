# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2018/02/14 13:22:32 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = test

# Compiler
CC = gcc

# Directories
SRC_PATH = ./
OBJ_PATH = obj/
LIB_PATH = ./../libft
INC_PATH = ./../includes\
		   $(LIB_PATH)/includes\
		   $(TESTS_PATH)

TESTS_PATH = tests/

# Includes & libraries
CPPFLAGS = $(addprefix -I, $(INC_PATH))
LDFLAGS = -L $(LIB_PATH)
LDLIBS = -lft

# Sources
SRC_TEST = $(TESTS_PATH)main.c\
		   $(TESTS_PATH)compare.c\
		   $(TESTS_PATH)call_both.c\
		   $(TESTS_PATH)read.c\
		   $(TESTS_PATH)flag_no.c\
		   $(TESTS_PATH)flag_d.c\
		   $(TESTS_PATH)flag_o.c\
		   $(TESTS_PATH)flag_u.c\
		   $(TESTS_PATH)flag_x.c\
		   $(TESTS_PATH)flag_capital_D.c\
		   $(TESTS_PATH)flag_capital_O.c\
		   $(TESTS_PATH)flag_capital_U.c\
		   $(TESTS_PATH)flag_capital_X.c\
		   $(TESTS_PATH)flag_c.c\
		   $(TESTS_PATH)flag_s.c\
		   $(TESTS_PATH)flag_b_bonus.c\

SRC_NAME = \
		   ft_printf.c\
		   get_chars_to_convert.c\
		   parser.c\
		   printer.c\
		   \
		   indicators_manager.c\
		   flags_manager_part1.c\
		   flags_manager_part2.c\
		   precision_manager_part1.c\
		   size_manager.c\
		   unicode_converter.c\
		   \
		   arg_int.c\
		   arg_char.c\
		   arg_string.c\

SRC_ALL = $(SRC_NAME) $(SRC_TEST)

OBJ_NAME = $(SRC_ALL:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_ALL))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags with OS Compatibiliy
OS = $(shell uname)
ifeq ($(OS), Darwin)
	FLAGS_DEFAULT = -Werror -Wall -Wextra
endif
ifeq ($(OS), Linux)
	FLAGS_DEFAULT = -Wno-unused-result
endif
ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS := $(ADDFLAGS)
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS := $(FLAGS_DEFAULT) -ansi -pedantic -g $(ADDFLAGS)
	endif
else
	CFLAGS := $(FLAGS_DEFAULT) $(ADDFLAGS)
endif

# **************************************************************************** #
# SPECIALS CHARS                                                               #
# **************************************************************************** #
LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BOLD = \033[1m
LOG_UNDERLINE = \033[4m
LOG_BLINKING = \033[5m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

TITLE = $(LOG_CLEAR)$(LOG_BLUE)
END_TITLE = $(LOG_NOCOLOR)
LINKING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tlinking " \
				".................. $(LOG_VIOLET)$<$(LOG_NOCOLOR)"
ASSEMBLING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tassembling " \
			 	"............... $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
INDEXING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tindexing " \
			 	"................. $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
OBJECTS_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion " \
				"............ $(LOG_RED)×$(LOG_NOCOLOR)"
BIN_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion " \
				"............. $(LOG_RED)×$(LOG_NOCOLOR)"

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #
.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): libft_make $(OBJ_PATH) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo -e $(ASSEMBLING)

libft_make:
	@make -C $(LIB_PATH)

$(OBJ_PATH):
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@echo -e "--$(LOG_CLEAR)Flags : $(CFLAGS)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)$(TESTS_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(ADDFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -e $(LINKING)

clean:
	@echo -e "$(TITLE)clean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e "$(TITLE)clean libft$(END_TITLE)"
	@make -C $(LIB_PATH) clean

fclean:
	@echo -e "$(TITLE)fclean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)
	@echo -e "$(TITLE)fclean libft$(END_TITLE)"
	@make -C $(LIB_PATH) fclean

re: fclean all

norme:
	norminette $(SRC_NAME)
	norminette $(addprefix $(INC_PATH), *.h)

# **************************************************************************** #
# Personal notes :                                                             #
#                                                                              #
# $@ : rule's name                                                             #
# $^ : all dependencies after ':'                                              #
# $< : corresponding dependency                                                #
# || : of there is an error, execute the command after the double pipe         #
#                                                                              #
# **************************************************************************** #
