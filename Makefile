##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Main Makefile for asm lib C
##

NAME	=	libasm.so

SRC =	strlen.asm	\
		strchr.asm  \
		strrchr.asm \
		memset.asm \
		memcopy.asm \
		strcmp.asm \
		strncmp.asm \
		strcasecmp.asm \
		strstr.asm \
		memmove.asm \
		strpbrk.asm \
		strcspn.asm

ASM = nasm -f elf64

LD = ld -shared

CC = gcc

OBJ = $(SRC:.asm=.o)

LD_LID_ENV = @export LD_PRELOAD=./$(NAME)

# may not need to be unset cause its Makefile variable
LD_LID_UNSET = @unset LD_PRELOAD

TESTS = Tests/test_strlen.c \
		Tests/test_strchr.c \
		Tests/test_strrchr.c \
		Tests/test_memset.c \
		Tests/test_memcopy.c \
		Tests/test_strcmp.c \
		Tests/test_strncmp.c \
		Tests/test_strcasecmp.c \
		Tests/test_strstr.c \
		Tests/test_memmove.c \
		Tests/test_strpbrk.c \
		Tests/test_strcspn.c

TEST_NAME = unit_tests

TESTS_OBJ = $(TESTS:.c=.o)

TEST_INC = -L. -lasm -lcriterion --coverage --debug

all: $(OBJ)
	$(LD) -o $(NAME) $(OBJ) -fPIC

$(OBJ): %.o : %.asm
	$(ASM) $< -o $@

clean:
	@rm -f $(OBJ) $(TESTS_OBJ)

fclean:	clean
	$(LD_LID_UNSET)
	@rm -f $(NAME) $(TEST_NAME)

re:	fclean all

unit_tests: re $(TESTS_OBJ)
	$(LD_LID_ENV)
	$(CC) -g3 -o $(TEST_NAME) $(TESTS_OBJ) $(TEST_INC)

tests_run: unit_tests
	LD_PRELOAD=./$(NAME) ./$(TEST_NAME)
	$(clean)

.PHONY: all re unit_tests tests_run clean fclean