# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 10:08:28 by nel-mous          #+#    #+#              #
#    Updated: 2023/02/09 10:32:11 by nel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c fractol.c utils.c hook.c to_float.c

SRCS_BONUS = main_bonus.c tricorn_bonus.c view_bonus.c multibrot_bonus.c utils_bonus.c hook_bonus.c tofloat_bonus.c fractol_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME	= Libft/libft.a

NAME_F	= fractol

NAME_B	= fractol_bonus

CC 		= cc 

CFLAGS	= -Wall -Wextra -Werror

LBXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM		= rm -f 

%.o: %.c fractol.h fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_F)

bonus: $(NAME_B)

$(NAME_F): $(OBJS) $(NAME) 
	$(CC) $(CFLAGS) $(OBJS) $(LBXFLAGS) $(NAME) -o $@

$(NAME_B): $(OBJS_BONUS) $(NAME) 
	cc $(CFLAGS) $(LBXFLAGS) $(OBJS_BONUS) $(NAME) -o $@

$(NAME):
	make -sC Libft all

clean:
	make -sC Libft fclean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME_F)
	$(RM) $(NAME_B)

re: fclean all


