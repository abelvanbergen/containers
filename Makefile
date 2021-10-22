# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-ber <avan-ber@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/05 10:29:50 by avan-ber      #+#    #+#                  #
#    Updated: 2021/10/11 11:55:20 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = clang++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES =	ft_vector.hpp \
			ft_iterator.hpp \
			ft_utils.hpp \
			ft_random_access_iterator.hpp

SRCS = main.cpp

test:
	$(CC) $(C++FLAGS) $(SRCS) -o ft && ./ft > res_ft && $(CC) $(C++FLAGS) $(SRCS) -D STD -o std && ./std > res_std && diff res_std res_ft

teststd:
	$(CC) $(C++FLAGS) $(SRCS) -D STD -o std && ./std > res_std

testft:
	$(CC) $(C++FLAGS) $(SRCS) -o ft && ./ft

fclean:
	rm -rf res_ft res_std ft std
re: fclean test

.PHONY: fclean re test teststd testft
