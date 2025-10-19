SRC = main.cpp Bureaucrat.cpp AForm.cpp
SRC_FILES = $(addprefix src/, $(SRC))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = obj
CXX = c++ -Wall -Wextra -Werror -std=c++98 -Iinc
NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
