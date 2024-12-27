#pragma once

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

void mx_printerr(const char *str);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *str);
bool mx_isspace(char c);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
int mx_count_words(const char *str);

