#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>


typedef struct  s_list 
{
    void *data;
    struct s_list *next;
}   t_list;

int mx_tolower(int c);
bool cmp(void *a, void *b);
void mx_printerr(const char*s);
void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b));
t_list *mx_create_node(void *data);
int mx_list_size(t_list *list);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
void mx_pop_index(t_list **list, int index);
void mx_push_back(t_list **list, void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_index(t_list **list, void *data, int index);
t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b));
int mx_strlen(const char *s);
int mx_strcmp (const char *s1, const char *s2);
int mx_strcmp_changed (const char *s1, const char *s2);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
bool mx_isdigit(char c);
bool mx_isspace(char c);
long mx_atoi(const char* str);
char *mx_strcpy(char* dst, const char* src);
void mx_clear_list(t_list **list);

