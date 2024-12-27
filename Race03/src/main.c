#include "../inc/header.h"

int mx_random_range(int min, int max) 
{
    return min + (rand() % (max - min + 1));
}

wchar_t mx_get_random_hiragana_alphabet(void) 
{
    wchar_t Japanese_Hiragana_alphabet[] = L"あいうえおかきくけこさしすそたちつてとなのぬねのはひふへほまみむめもやゆよらりるれろわをん";

    return Japanese_Hiragana_alphabet[mx_random_range(0, sizeof(Japanese_Hiragana_alphabet) / sizeof(wchar_t) - 1)];
}

t_drops *mx_drops_random(int size, int x, int y)
{
    t_drops *drops = malloc(sizeof(t_drops));

    if(drops == NULL)
    {
        return NULL;
    }

    drops -> drops_size = size;
    drops -> drops_x = x;
    drops -> drops_y = y;
    drops -> prev = NULL;

    if((drops -> data = malloc(sizeof(wchar_t) * size)) == NULL) 
    {
        free(drops);
        return NULL;
    }

    for(int i = 0; i < size; i++) 
    {
        drops->data[i] = mx_get_random_hiragana_alphabet();
    }

    return drops;
}

void mx_drops_move_down(t_drops *drops) 
{
    if(drops == NULL) 
    {
        return;
    }

    wchar_t *data = drops -> data;
    int drop_size = drops -> drops_size;

    for(int i = 0; i < drop_size - 1; i++) 
    {
        data[i] = data[i + 1];
    }

    data[drop_size - 1] = mx_get_random_hiragana_alphabet();
    drops -> drops_y++;
}

void mx_drops_render(t_drops *drops) 
{
    wchar_t *data = drops -> data;
    int drop_size = drops -> drops_size;
    int drop_x = drops -> drops_x;
    int drop_y = drops -> drops_y;

    attron(COLOR_PAIR(0));
    mvprintw(drop_y, drop_x, "%lc", data[drop_size - 1]);
    attroff(COLOR_PAIR(0));

    for(int i = 1; i < drops -> drops_size; i++) 
    {
        attron(COLOR_PAIR(1));
        mvprintw(drop_y - i, drop_x, "%lc", data[drop_size - i - 1]);
        attroff(COLOR_PAIR(1));
    }
}

bool mx_list_cmp(void *a, void *b) 
{
    return a == b;
}


void mx_handle_update(t_drops_list *node) 
{
    int max_Y = getmaxy(stdscr);

    t_drops *drops = node -> data;

    mx_drops_render(drops);
    mx_drops_move_down(drops);
    
    int first_char_y = drops -> drops_y - drops -> drops_size;

    if(drops -> prev == NULL && first_char_y >= 5) 
    {
        t_drops *drops_new = mx_drops_random( mx_random_range(1, max_Y), drops -> drops_x, -mx_random_range(0, 20));
        t_drops_list *temp = node -> next;
        node -> next = mx_create_node(drops_new);
        node -> next -> next = temp;
        drops -> prev = drops_new;

    }

    if(first_char_y >= max_Y) 
    {
        mx_drops_free(&drops);
        node -> data = drops;
    }
}

void mx_clear_drops(t_drops_list *node) 
{
    t_drops *drops = node -> data;
    mx_drops_free(&drops);
    node -> data = drops;
}

void mx_drops_free(t_drops **drops) 
{
    if(drops == NULL || *drops == NULL) 
    {
        return;
    }

    free((*drops) -> data);
    free(*drops);
    *drops = NULL;
}

int main(void) 
{
    setlocale(LC_ALL, "");

    srand(time(NULL));

    initscr();
    halfdelay(1);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    int max_X, max_Y;

    getmaxyx(stdscr, max_Y, max_X);

    t_drops_list *drops = NULL;

    for(int i = 0; i < max_X; i++) 
    {
    	t_drops *new_drops = mx_drops_random(mx_random_range(1, max_Y), i, -mx_random_range(0, 20));
    	mx_push_back(&drops, new_drops);
    }

    char *matrix_lines[] = {
        "Wake up , Neo..",
        "The Matrix has you..",
        "Follow the white rabbit",
        "Knock, knock, Neo",
    };

    for(int i = 0; i < 4; i++) 
    {
        erase();

        int line_len = mx_strlen(matrix_lines[i]);

        for(int j = 0; j < line_len; j++) 
        {
            mvaddch(0, j, matrix_lines[i][j] | COLOR_PAIR(1));
            refresh();
            usleep(200000);
        }

        usleep(800000);
    }

    while(getch() != 'q')
    {
        erase();
        mx_foreach_list(drops, &mx_handle_update);
        mx_del_node_if(&drops, NULL, &mx_list_cmp);
        refresh();
        usleep(1);
    }

    mx_foreach_list(drops, &mx_clear_drops);
    mx_del_node_if(&drops, NULL, &mx_list_cmp);
    mx_clear_list(&drops);
    endwin();

    exit(0);
}

