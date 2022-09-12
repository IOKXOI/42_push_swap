# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 18:58:29 by sydauria          #+#    #+#              #
#    Updated: 2022/09/11 18:02:39 by sydauria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
NAMEDEBUGG=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra -MMD -g3 -O0
SRCDIR=./srcs/
OBJSDIR=./objs/
INCLUDES=./includes
BUILD = build
BUILDDEBBUG = build
INCLUDES = -I ./includes/

SRC_ARGV_HANDLING=$(addprefix argv_handling/, \
					argv_to_chain_list.c\
					parsing.c\
					input_management.c\
					input_processing.c)

SRC_CHAIN_LIST=$(addprefix chain_list/, \
					list_browser.c)

SRC_SORTING=$(addprefix sorting/, \
				radix.c)

SRC_FREE=$(addprefix free/, \
					free.c)

SRC_MOOVE=$(addprefix mooves/, \
			move.c)


SRCS = $(addprefix $(SRCDIR), $(SRC_ARGV_HANDLING)\
		$(SRC_CHAIN_LIST)\
		$(SRC_SORTING)\
		$(SRC_FREE)\
		$(SRC_MOOVE)\
		push_swap.c)

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS := $(SRCS:%.c=$(BUILD)/%.o)
#OBJECTS := $(SRCS:%.c=$(BUILDDEBBUG)/%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: $(NAME)

-include:$(DEPS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) -o $@

$(BUILD)/%.o: %.c ./includes/*.h
	@mkdir -p '$(@D)'
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
#$(NAMEDEBUGG): $(OBJECTS)
#	$(CC) $(OBJECTS) $(INCLUDES) -o $@
#	
#$(BUILDDEBBUG)/%.o: %.c ./includes/*.h
#	$(CC) $(CFLAGS) -g $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

#debug: $(NAMEDEBUGG)
#	fclean
#	$(CC) $(OBJECTS) $(INCLUDES) -o push_swap

.PHONY: all clean fclean re debug
