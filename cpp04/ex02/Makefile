NAME	=	Abstract

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp\
				Animal.cpp\
				Dog.cpp\
				Cat.cpp\
				Brain.cpp\
				
INCS		=	Animal.hpp\
				Dog.hpp\
				Cat.hpp\
				Brain.hpp\

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