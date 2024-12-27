#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mx_count_words(const char *str, char delimiter);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char*src, int len);
char *mx_strnew(const int size);
char **mx_strsplit(char const *s, char c);

char **mx_strsplit(char const *s, char c)
{
    if(s == NULL) 
    {
        return NULL;
    }

    int word_count = 0;
    int len = 0;
    char **result = (char **)malloc(8 * word_count);
    int word_start = 0;
    int word_end = 0;

    if(result == NULL)
    {
        return NULL;
    }

    while(s[len] != '\0')
    {
        if(s[len] != c)
        {
            word_count++;

            while(s[len] != c && s[len] != '\0')
            {
                len++;
            }
        } else
        {
            len++;
        }
    }

    for(int i = 0; i < len; i++)
    {
        if(s[i] != c)
        {
            word_start = i;

            while(s[i] != c && s[i] != '\0')
            {
                i++;
            }

            int word_len = i - word_start;
            result[word_end] = mx_strnew(word_len + 1);

            if(result[word_end] == NULL)
            {
                for(int j = 0; j < word_end; j++)
                {
                    mx_strdel(&result[j]);
                }
                mx_strdel(result);
                return NULL;
            }
            mx_strncpy(result[word_end], s + word_start, word_len);
            result[word_end][word_len] = '\0';
            word_end++;
        }
    }

    result[word_end] = NULL;

    return result;
}

