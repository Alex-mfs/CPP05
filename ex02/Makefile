# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 14:06:18 by alex              #+#    #+#              #
#    Updated: 2025/05/27 10:36:14 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = forms
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

ASANFLAGS = -fsanitize=address -g
asan: CXXFLAGS += $(ASANFLAGS)
asan: re

# Run with macOS leaks
leaks: re
	leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re asan leaks