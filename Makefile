CC	=	gcc

CFLAGS = -lcurses -g -g3 -O0

TARGET	=	bonsai

SRC	:=	src/main.c	\
		src/visual.c	\
		src/utils.c	\
		src/lindenmayer.c	\

OBJ := $(SRC:.c=.o)

all: build

build:	$(OBJ)
	$(CC) $^ -o $(TARGET) $(CFLAGS)

clean:
	rm -rf src/*.o

fclean:	clean
	rm -rf $(TARGET)

.PHONY: fclean all
