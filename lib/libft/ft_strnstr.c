/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:18:40 by vrandria          #+#    #+#             */
/*   Updated: 2024/02/23 08:18:46 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	li_len;
	size_t	i;

	i = 0;
	li_len = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	while ((*big != 0) && (i < len))
	{
		if ((ft_strncmp(big, little, li_len) == 0) && (i + li_len <= len))
			return ((char *)big);
		big++;
		i++;
	}
	return (0);
}
