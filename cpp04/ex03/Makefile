NAME	=	AMateria

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -O0

SRCS		=	main.cpp\
				AMateria.cpp\
				Ice.cpp\
				Cure.cpp\
				Character.cpp\
				MateriaSource.cpp\
				
INCS		=	AMateria.hpp\
				Ice.hpp\
				Cure.hpp\
				ICharacter.hpp\
				Character.hpp\
				IMateriaSource.hpp\
				MateriaSource.hpp\

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