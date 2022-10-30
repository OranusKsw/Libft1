/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:46:46 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/10/29 12:31:16 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*tmp;
	char	*end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	end = (char *)s1 + (ft_strlen(s1));
	while (isset(*s1, set) && len-- && *s1)
		s1++;
	while (isset(*(end - 1), set) && (len - 1) >= 0)
	{
		len--;
		end--;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	tmp = str;
	while (s1 != end)
		*(str++) = *(s1++);
	*str = '\0';
	return (tmp);
}
