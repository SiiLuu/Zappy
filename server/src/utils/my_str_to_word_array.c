/*
** EPITECH PROJECT, 2019
** ON SYNTHESE PAS NOUS
** File description:
** Requirement.c
*/

#include <stdlib.h>

static int is_cut(char c, char delim)
{
    if ((c == ' ' || c == '\n' || c == '\t') && delim != ' ')
        return (1);
    if (c > 32 && c < 127 && c != delim)
        return (1);
    return (0);
}

static int count_words(char const *str, char delim)
{
    int	word = 0;
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (word == 0 && is_cut(str[i], delim) == 1) {
            word = 1;
            nb_words = nb_words + 1;
            i++;
        }
        if (word == 1 && is_cut(str[i], delim) == 0)
            word = 0;
        if (str[i] == '\0')
            break;
    }
    return (nb_words);
}

static void	my_strncpy(char *new_str, char const *str, \
int begin, int end)
{
    int	i = 0;

    while (begin <= end) {
        new_str[i] = str[begin];
        begin = begin + 1;
        i = i + 1;
    }
    new_str[i] = '\0';
}

static int save_words(char **tab, char const *str, int nb_words, char delim)
{
    int	i = 0;
    int	begin = 0;
    int	actual = 0;

    for (actual = 0; actual < nb_words; actual++) {
        for (;str[i] && is_cut(str[i], delim) == 0; i++);
        begin = i;
        for (;str[i] && is_cut(str[i], delim) == 1; i++);
        tab[actual] = malloc(sizeof(char) * ((i - 1) - begin + 2));
        if (tab[actual] == NULL)
            return (84);
        my_strncpy(tab[actual], str, begin, i - 1);
        i++;
    }
    return (0);
}

char **my_str_to_word_array(char const *str, char delim)
{
    int	nb_words = 0;
    char **tab = NULL;

    nb_words = count_words(str, delim);
    if (nb_words == -1)
        return (NULL);
    tab = malloc(sizeof(char *) * (nb_words + 1));
    if (tab == NULL)
        return (NULL);
    if (save_words(tab, str, nb_words, delim) == 84)
        return (NULL);
    tab[nb_words] = NULL;
    return (tab);
}