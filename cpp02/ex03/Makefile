NAME	=	ex03

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp\
				Fixed.cpp\
				Point.cpp\
				bsp.cpp

INCS		=	Fixed.hpp\
				Point.hpp\

OBJS	=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME)	: $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY = all clean fclean re