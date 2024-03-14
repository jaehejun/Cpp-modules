NAME	=	ScavTrap

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -Wshadow

SRCS		=	main.cpp\
				ClapTrap.cpp\
				ScavTrap.cpp\

INCS		=	ClapTrap.hpp\
				ScavTrap.hpp\

OBJS	=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME)	: $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY = all clean fclean re