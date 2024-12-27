CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic -D_XOPEN_SOURCE=600 -D_POSIX_C_SOURCE=200112L
CLIBS := -lncurses
NAME := matrix_rain

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME): $(wildcard ./inc/*.h) $(wildcard ./src/*.c)
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c ./src/*.c
	mv ./*.o ./obj
	$(CC) $(CLIBS) $(CFLAGS) -o $(NAME) ./obj/*.o

clean:
	rm -rf ./obj
	rm -rf ./$(NAME)

uninstall:
	rm -rf ./obj
	rm -rf ./$(NAME)

reinstall: uninstall all

