#include <stdio.h>
#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_strnew(const int size);
char *mx_concat_words(char **words);

char *mx_concat_words(char **words)
{
    if(words == NULL)
    {
        return NULL;
    }

    int words_len = 0;
    char *result = mx_strnew(words_len + 1);

    if(result == NULL)
    {
        return NULL;
    }

    for(int i = 0; words[i] != NULL; i++)
    {
        words_len += mx_strlen(words[i]);
    }

    int word_index = 0;

    for(int i = 0; words[i] != NULL; i++)
    {
        mx_strcpy(result + word_index, words[i]);
        word_index += mx_strlen(words[i]);

        if(words[i + 1] != NULL)
        {
            result[word_index] = ' ';
            word_index++;
        }
    }

    return result;
}

