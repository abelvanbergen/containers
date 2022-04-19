# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-ber <avan-ber@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/05 10:29:50 by avan-ber      #+#    #+#                  #
#    Updated: 2022/04/19 11:36:27 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 			ft_containers
STD_NAME =		std_containers

CC =			clang++
FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

SRC =			main.cpp
FT_RES =		ft_res.txt
STD_RES =		std_res.txt

INCLUDES =	containers/ft_map.hpp \
			containers/ft_stack.hpp \
			containers/ft_vector.hpp \
			utils/ft_bidirectional_iterator.hpp \
			utils/ft_mapNodes.hpp \
			utils/ft_pair.hpp \
			utils/ft_random_access_iterator.hpp \
			utils/ft_reverse_iterator.hpp \
			utils/ft_type_traits.hpp \
			utils/ft_utils.hpp

C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(INCLUDES)
	$(CC) $(C++FLAGS) $(SRC) -I containers -I utils -o $(NAME)
	
$(STD_NAME):
	$(CC) $(C++FLAGS) $(SRC) -D STD -o $(STD_NAME)

test: $(NAME) $(STD_NAME)
	./$(NAME) > $(FT_RES)
	./$(STD_NAME) > $(STD_RES)
	diff $(FT_RES) $(STD_RES)

testft: ft_fclean $(NAME)
	./$(NAME)

teststd: std_fclean $(STD_NAME)
	./$(STD_NAME)

clean:
	$(RM) $(FT_RES) $(STD_RES)

fclean: clean
	$(RM) $(NAME) $(STD_NAME)

ft_fclean:
	$(RM) $(FT_RES) $(NAME)

std_fclean:
	$(RM) $(STD_RES) $(STD_NAME)

time: $(NAME) $(STD_NAME)
	time ./$(NAME) > $(FT_RES)
	time ./$(STD_NAME) > $(STD_RES)
	diff $(FT_RES) $(STD_RES)

re: fclean all

.PHONY: test teststd testft ft_fclean std_fclean clean fclean re time
