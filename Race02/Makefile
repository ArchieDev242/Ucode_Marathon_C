CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := way_home

all: MINILIBMX

MINILIBMX:
	$(CC) $(CFLAGS) src/*.c -o $(NAME)

clean:
	rm -f $(NAME)

uninstall:
	rm -f $(NAME)

reinstall:
	make uninstall
	make

