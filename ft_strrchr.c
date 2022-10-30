/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:09:26 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/10/29 21:43:55 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)0;
	while (*s)
	{
		if ((char)*s == (char)c)
			tmp = (char *)s;
		s++;
	}
	if ((char)*s == (char)c)
		tmp = (char *)s;
	return (tmp);
}
