#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct s_drops_list 
{
    void *data;
    struct s_drops_list *next;
}   t_drops_list;

typedef struct s_drops 
{
    wchar_t *data;
    int drops_size;
    int drops_x;
    int drops_y; 
    struct s_drops *prev;
}   t_drops;


int mx_strlen(const char *s);
bool mx_isdigit(int c);
t_drops_list *mx_create_node(void *data);
void mx_push_front(t_drops_list **list, void *data);
void mx_drops_free(t_drops **drops);
void mx_push_index(t_drops_list **list, void *data, int index);
void mx_pop_index(t_drops_list **list, int index);
void mx_clear_list(t_drops_list **list);
void mx_push_back(t_drops_list **list, void *data);
void mx_pop_back(t_drops_list **list);
void mx_pop_front(t_drops_list **list);
void mx_foreach_list(t_drops_list *list, void (*f)(t_drops_list *node));
void mx_del_node_if(t_drops_list **list, void *del_data, bool (*cmp)(void *a, void *b));
t_drops *mx_drops_random(int size, int x, int y);
void mx_drops_move_down(t_drops *drops);
void mx_drops_render(t_drops *drops);

