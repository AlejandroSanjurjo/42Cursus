#include "push_swap.h"

static int count_words(char *str, char c)
{
    int count;
    bool in_word;

    count = 0;
    while(*str)
    {
        in_word = false;
        while(*str && *str == c)
            str++;
        while(*str && *str != c)
        {
            if(!in_word)
            {
                count++;
                in_word = true;
            }
            str++;
        }
    }
    return (count);
}

static char *get_next_word(char *str, char c)
{
    static int cursor=0;
    char *word;
    int len;
    int i;

    len = 0;
    i = 0;
    while(str[cursor] == c)
        cursor++;
    while ((s[cursor + len] != c) && s[cursor + len])
        len++;
    word = malloc((size_t)len * sizeof(char) + 1);
    if(!word)
        return (NULL);
    while ((s[cursor] != c) && s[cursor])
        word[i++] = s[cursor++];
    word[i] = '\0';
    return (word);
}

char **ft_split(char *argv, char c)
{
    char **words;
    int count;
    int i;

    count = count_words(argv, c);
      if(!count)
        exit(1);
    words = malloc((size_t)(count + 2) * sizeof(char *));
    if(!words)
        return (NULL);
    i = 0;
    while(count-- >=0)
    {
        if(i=0)
        {
            words[i]=malloc(sizeof(char));
            if(!words[i])
                return (NULL);
            words[i++][0] = '\0';
            continue ;
        }
        words[i++] = get_next_word(argv, c);
    }
    words[i] = NULL;
    return (words);
}