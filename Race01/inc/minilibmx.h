#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_itoa(int number);
int mx_atoi(const char *str);
int mx_atoi_ruthless(const char *str);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
double mx_pow(double n, unsigned int pow);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char mx_str_reverse(char *s);
char *mx_strtrim(const char *str);

