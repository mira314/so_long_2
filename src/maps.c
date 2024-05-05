/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:34:52 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/23 08:11:26 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void count_object(char *str, t_maps *maps)
{
	int	i;

	maps->collect = 0;
	maps->player = 0;
	maps->exit = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'C')
			maps->collect += 1;
		if (str[i] == 'E')
			maps->exit += 1;
		if (str[i] == 'P')
			maps->player += 1;
		i++;
	}
}

char	*open_maps(char *ber)
{
  int  fd;
  char *maps;
  char	*mappers;
  char *tmp;
  
  maps = ft_strdup("");
  fd = open(ber, O_RDONLY);
  while (1)
    {
      mappers = get_next_line(fd);
      if (!mappers)
        break ;
      tmp = ft_strdup(maps);
      free(maps);
      maps = ft_strjoin((char const *)tmp,(char const *)mappers);
      free(tmp);
      free(mappers);
    }
  free(mappers);
  close(fd);
  return (maps);
}

t_maps	*builder_maps(char *ber)
{
	t_maps	*maps;
	char		*maps_line;

	maps = malloc(sizeof(t_maps));
	maps->y = 0;
	maps_line = open_maps(ber);
	count_object(maps_line, maps);
	maps->mapsx_y = ft_split((const char *)maps_line, '\n');
	maps->x = ft_strlen(maps->mapsx_y[0]);
	while (maps->mapsx_y[maps->y] != NULL)
		maps->y = maps->y + 1;
	free(maps_line);
	watter_error(maps);
	return(maps);
}

void  see_maps(t_maps *maps)
{
	int y;

	y = 0;

	while (y < maps->y)
	{
		ft_printf("%s\n",maps->mapsx_y[y]);
		y++;
	}
	ft_printf("collect = %d\n",maps->collect);
	ft_printf("exit = %d\n",maps->exit);
	ft_printf("player = %d\n",maps->player);
}

void free_maps(t_maps *maps)
{
	int	i;

	i = 0;
	while(i <= maps->y)
	{
		free(maps->mapsx_y[i]);
		i++;
	}
	free(maps->mapsx_y);
	free(maps);
}
