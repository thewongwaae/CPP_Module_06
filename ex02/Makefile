NAME	= Identify
CPP		= c++ -fsanitize=address
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

SRC		= main.cpp A.cpp B.cpp C.cpp Base.cpp
INC		= A.hpp B.hpp C.hpp Base.hpp

OBJ		= $(SRC:%.cpp=%.o)

all : $(NAME)

%.o : %.cpp $(INC)
	@printf "\033[0;32mGenerating objects... %-33.33s\r" "$@"
	@$(CPP) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@printf "\033[0;32mGenerating executable... %-33.33s\n" "$@"
	@$(CPP) $(FLAGS) $^ -o $@

clean :
	@printf "\033[0;31mCleaning objects... %-33.33s\n" "$(OBJ)"
	@$(RM) $(OBJ)

fclean : clean
	@printf "\033[0;31mCleaning executable... %-33.33s\n" "$(NAME)"
	@$(RM) $(NAME)

re : fclean all