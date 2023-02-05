# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 10:08:28 by nel-mous          #+#    #+#              #
#    Updated: 2023/02/05 09:50:38 by nel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c fractol.c map_pix_to_complex.c check_if_belongs.c draw.c zoom_in_out.c moving_view.c close.c to_float.c 

SRCS_BONUS = main_bonus.c tricorn_bonus.c view_bonus.c multibrot_bonus.c utils_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME	= Libft/libft.a

NAME_F	= fractol

NAME_B	= fractol_bonus

CC 		= cc 

CFLAGS	= -Wall -Wextra -Werror

LBXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM		= rm -f 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_F)

bonus: $(NAME_B)

$(NAME_F): $(OBJS) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LBXFLAGS) $(NAME) -o fractol

$(NAME_B): $(OBJS_BONUS) $(NAME)
	cc $(CFLAGS) $(LBXFLAGS) $(OBJS_BONUS) $(NAME) -o $@

$(NAME):
	make -C Libft all

clean:
	make -C Libft fclean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME_F)
	$(RM) $(NAME_B)

re: fclean all


