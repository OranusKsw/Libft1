/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:35:53 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/10/31 12:42:47 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_splitt(char **str)
{
	char	**tmp;

	if (!str || !(*str))
		return ;
	tmp = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(tmp);
}

static int	countword(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && !(*s == c))
		{
			word++;
			while (*s && !(*s == c))
				s++;
		}
	}
	return (word);
}

static int	*lenword(char const *s, char c, int word)
{
	int	*arr;
	int	i;

	arr = malloc(word * sizeof(int));
	i = 0;
	if (!arr)
		return (NULL);
	while (i < word)
		arr[i++] = 0;
	i = 0;
	while (word--)
	{
		while (*s && *s == c)
			s++;
		if (*s && !(*s == c))
		{
			while (*s && !(*s == c))
			{
				s++;
				arr[i]++;
			}
			i++;
		}
	}
	return (arr);
}

static char	**split(const char *s, char **str, char c, int *arr)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = countword(s, c);
	while (i < word)
	{
		while (*s && (*s == c))
			s++;
		j = 0;
		while (j < arr[i] && *s)
			str[i][j++] = *(s++);
		str[i][j] = '\0';
		i++;
	}
	free(arr);
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		*arr;
	int		i;

	if (!s)
		return (NULL);
	arr = lenword(s, c, countword(s, c));
	str = malloc((countword(s, c) + 1) * sizeof(char *));
	if (!str || !arr)
	{
		if (arr)
			free(arr);
		return (NULL);
	}
	i = -1;
	while (++i < countword(s, c))
	{
		str[i] = malloc(((arr[i] + 1) * sizeof(char)));
		if (!str[i])
		{
			free_splitt(str);
			return (NULL);
		}
	}
	return (split (s, str, c, arr));
}
