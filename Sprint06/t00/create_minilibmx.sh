clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c *.c
ar -rc minilibmx.a *.o
rm *.o

