/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 07:56:31 by vrandria          #+#    #+#             */
/*   Updated: 2024/06/23 08:55:42 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	acces_test(t_maps *maps, int x, int y)
{
	if (maps->mapsx_y[y + 1][x] == 'A')
		return (1);
	if (maps->mapsx_y[y - 1][x] == 'A')
		return (1);
	if (maps->mapsx_y[y][x + 1] == 'A')
		return (1);
	if (maps->mapsx_y[y][x - 1] == 'A')
		return (1);
	return (0);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != 'C')
	{
		return ;
	}
	map[y][x] = 'A';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	acces_collect(t_maps *maps, char target)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < maps->y)
	{
		while (x < maps->x)
		{
			if (maps->mapsx_y[y][x] == target)
			{
				if (acces_test(maps, x, y) == 0)
					return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	test_name_maps(char *name)
{
	int	len;

	len = ft_strlen(name);
	len = len - 4;
	if (ft_strncmp(&name[len], ".ber", 4))
	{
		return (1);
	}
	ft_printf("error, name path is not correct \n");
	return (0);
}
