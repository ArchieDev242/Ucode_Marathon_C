CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := parse_agents

INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)

all: $(NAME)

$(NAME):$(INC) $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(NAME)

uninstall:
	rm -f $(NAME)

reinstall:
	make uninstall
	make

