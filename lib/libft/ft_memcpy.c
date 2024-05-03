/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:22:51 by vrandria          #+#    #+#             */
/*   Updated: 2024/02/20 11:22:56 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*result;

	result = dest;
	if (!dest && !src)
		return (0);
	while (n--)
	{
		*(char *)dest++ = *(char *)src++;
	}
	return (result);
}
