#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_agent 
{
    char *name;
    int power;
    int strength;
}   t_agent;


int mx_strlen(const char *s);
void mx_printerr(const char*s);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
char *mx_strnew(const int size);
int mx_count_words(const char *str, char delimiter);
int mx_strcmp(const char *s1, const char *s2);
void mx_print_agents(t_agent **agents, int count_of_agents);
void mx_strdel(char **str);
void mx_print_agents(t_agent **agents, int count_of_agents);

