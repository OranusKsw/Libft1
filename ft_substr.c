/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:08:37 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/10/30 16:57:13 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;

	if (!s)
		return (NULL);
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		start = ft_strlen(s);
		len = 0;
	}
	ans = malloc((len + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans = ft_memcpy(ans, s + start, len);
	ans[len] = '\0';
	return (ans);
}
