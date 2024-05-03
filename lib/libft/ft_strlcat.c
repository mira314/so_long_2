/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:51 by vrandria          #+#    #+#             */
/*   Updated: 2024/02/20 14:06:54 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	i = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	result = ft_strlcpy(dst, src, size - i);
	return (result + i);
}
