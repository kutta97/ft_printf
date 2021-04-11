/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:33:39 by hyyang            #+#    #+#             */
/*   Updated: 2021/02/03 22:04:03 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, size_t *j, char c)
{
	size_t	len;

	len = 0;
	while (s[*j] == c)
		(*j)++;
	while (s[*j + len] != c && s[*j + len] != '\0')
		len++;
	return (len);
}

static char		**ft_malloc_error(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char		**words;
	size_t		count;
	size_t		wordlen;
	size_t		i;
	size_t		j;

	if (!s)
		return (0);
	count = ft_count_words(s, c);
	if (!(words = (char **)malloc((count + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	while (i < count)
	{
		wordlen = ft_wordlen(s, &j, c);
		if (!(words[i] = (char *)malloc((wordlen + 1) * sizeof(char))))
			return (ft_malloc_error(words));
		ft_strlcpy(words[i], &s[j], wordlen + 1);
		j += wordlen;
		i++;
	}
	words[i] = 0;
	return (words);
}
