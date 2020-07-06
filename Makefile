##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compilation
##

SRC_proj	=	src/main.cpp \
				src/Exceptions.cpp \
				src/AbstractVm.cpp \
				src/Operands.cpp \
				src/Commands.cpp \
				src/Parser.cpp \
				src/Factory.cpp \
				src/utils/AvmCleaner.cpp \
				src/utils/Misc.cpp \

SRC_test	= 	tests/test.c

OBJ		=	$(SRC_proj:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -g

LDFLAG	=	-lcriterion -lgcov

NAME	=	abstractVM

%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(OBJ) $(CFLAGS) -o $(NAME) -I./include

tests_run:
	g++ -o units $(SRC_proj) $(SRC_test) $(LDFLAG) --coverage
	./units

clean:
	rm -f $(OBJ) *.gcno *.gcda

fclean: clean
	rm -f $(NAME)

re: fclean all