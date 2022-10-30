/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:41:51 by okotsuwa          #+#    #+#             */
/*   Updated: 2022/09/11 14:38:56 by okotsuwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	ans = malloc(count * size);
	if (!ans)
		return (0);
	ft_bzero(ans, count * size);
	return (ans);
}
