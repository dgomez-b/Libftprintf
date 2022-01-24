# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:30:30 by dgomez-b          #+#    #+#              #
#    Updated: 2022/01/24 14:46:38 by dgomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a

LIBFT	=		./libft

SRCS	=		ft_printf.c

OBJS	=		$(SRCS:.c=.o)

FLAGS	=		-Wall -Wextra -Werror

all		:		$(NAME)

$(NAME)	:		$(OBJS)
				make -C $(LIBFT)
				gcc $(FLAGS) -I. -I$(LIBFT) -c $(SRCS)
				ar rc $(NAME) $(OBJS) $(LIBFT)/*.o

clean	:		$(OBJS)
				make clean -C $(LIBFT)
				rm -f $(OBJS)

fclean	:		clean
				make fclean -C $(LIBFT)
				rm -f $(NAME)

re		:		fclean $(NAME)

.PHONY	:		all clean fclean re