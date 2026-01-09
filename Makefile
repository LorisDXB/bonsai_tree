CC	=	gcc
TARGET	=	test

SRC	:=	src/main.c	\

OBJ := $(SRC:.c=.o)

all: build

build:	$(OBJ)
	$(CC) $< -o $(TARGET)

clean:
	rm -rf src/*.o

fclean:	clean
	rm -rf $(TARGET)

.PHONY: fclean all
