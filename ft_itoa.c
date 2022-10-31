/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:18:52 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/10/30 16:53:32 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countn(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	char			*tmp;
	int				len;
	unsigned int	nb;

	len = countn(n);
	str = malloc(len * sizeof(char) + 1);
	tmp = str;
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		nb = n * -1;
	}
	else
		nb = n;
	str += len;
	*str = '\0';
	while (len-- > (n < 0))
	{
		*(--str) = (nb % 10) + '0';
		nb /= 10;
	}
	return (tmp);
}
