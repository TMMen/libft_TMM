/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:55:12 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:36:45 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
			wordcount++;
		i++;
	}
	return (wordcount);
}

static int	ft_wi(char const *s, char c, int which_word)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
			word_counter++;
		if (word_counter == which_word)
			break ;
		i++;
	}
	return (i);
}

static int	ft_wlen(char const *s, char c, int which_word)
{
	int	i;
	int	word_counter;
	int	char_counter;

	i = 0;
	word_counter = 0;
	char_counter = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
			word_counter++;
		if (word_counter == which_word && s[i] != c)
			char_counter++;
		i++;
	}
	return (char_counter);
}

static void	ft_free_if_error(char **wordtable, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(wordtable[j]);
		j++;
	}
	free(wordtable);
}

char	**ft_split(char const *s, char c)
{
	char	**wtab;
	int		wordcount;
	int		i;

	wordcount = ft_count_words(s, c);
	wtab = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!wtab)
		return (NULL);
	wtab[wordcount] = NULL;
	i = 0;
	while (i < wordcount)
	{
		wtab[i] = (char *)malloc((ft_wlen(s, c, i + 1) + 1) * sizeof(char));
		if (!wtab[i])
		{
			ft_free_if_error(wtab, i);
			return (NULL);
		}
		ft_strlcpy(wtab[i], &s[ft_wi(s, c, i + 1)], ft_wlen(s, c, i + 1) + 1);
		i++;
	}
	return (wtab);
}
