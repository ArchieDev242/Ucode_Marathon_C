CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := read_file

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) src/*.c -o $(NAME)

clean:
	rm -f $(NAME)

uninstall:
	rm -f $(NAME)

reinstall:
	make uninstall
	make

