/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:35:53 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/10/29 21:09:14 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	issep(char c, char s)
{
	if (c == s)
		return (1);
	return (0);
}

int	countword(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && issep(*s, c))
			s++;
		if (*s && !issep(*s, c))
		{
			word++;
			while (*s && !issep(*s, c))
				s++;
		}
	}
	return (word);
}

int	*lenword(char const *s, char c, int word)
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
		while (*s && issep(*s, c))
			s++;
		if (*s && !issep(*s, c))
		{
			while (*s && !issep(*s, c))
			{
				s++;
				arr[i]++;
			}
			i++;
		}
	}
	return (arr);
}

char	**split(const char *s, char **str, char c, int *arr)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = countword(s, c);
	while (i < word)
	{
		while (*s && issep(*s, c))
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
	int		word;
	int		i;

	if (!s)
		return (NULL);
	word = countword(s, c);
	arr = lenword(s, c, word);
	if (!arr)
		return (NULL);
	str = malloc((word + 1) * sizeof(char *));
	if (!str)
	{
		free(arr);
		return (NULL);
	}
	i = -1;
	while (++i < word)
		str[i] = malloc((arr[i] * sizeof(char)) + 1);
	str = split(s, str, c, arr);
	return (str);
}
/*
#include<stdio.h>
int main()
{
	char **str;
	int	i;
	i= 0;
	str = ft_split("  tripouille  42  ", ' ');
	while(str[i])
	{
		free(str[i]);
		i = i + 1;
	}
	free(str);
	return (0);
}*/
