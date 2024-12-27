CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := DECRYPT_MATH_EXPRESSION
EXECUTABLE := part_of_the_matrix

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME):
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c ./src/*.c
	mv ./*.o ./obj
	$(CC) $(CFLAGS) -o $(EXECUTABLE) ./obj/*.o


clean:
	rm -rf ./obj

uninstall:
	rm -rf ./obj
	rm -rf $(EXECUTABLE)

reinstall: uninstall $(NAME)

