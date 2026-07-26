NAME		= ft_containers
STD_NAME	= std_containers

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDES	= -I include

SRC_DIR		= tests
OBJ_DIR		= obj

SRCS		= $(SRC_DIR)/main.cpp

FT_OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/ft/%.o)
STD_OBJS	= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/std/%.o)


all: $(NAME) $(STD_NAME)

$(NAME): $(FT_OBJS)
	$(CXX) $(CXXFLAGS) $(FT_OBJS) -o $(NAME)

$(STD_NAME): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) $(STD_OBJS) -o $(STD_NAME)

$(OBJ_DIR)/ft/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/std/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -D USE_STD=1 $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(STD_NAME)

re: fclean all

.PHONY: all clean fclean re
