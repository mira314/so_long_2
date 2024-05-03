/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 07:05:33 by vrandria          #+#    #+#             */
/*   Updated: 2024/02/24 17:30:09 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const char *src, size_t n)
{
	char	*result;

	result = dest;
	if (!dest && !src)
		return (0);
	if ((unsigned char *)src < (unsigned char *)dest)
	{
		src += n;
		dest += n;
		while (n--)
		{
			*(char *)--dest = *(char *)--src;
		}
	}
	else
	{
		while (n--)
		{
			*(char *)dest++ = *(char *)src++;
		}
	}
	return (result);
}
