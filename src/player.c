/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:59:08 by vrandria          #+#    #+#             */
/*   Updated: 2024/06/23 07:32:43 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_player(t_xvar *mlx, t_win_list *win, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(mlx, "font/cat_f.xpm", &w, &h);
	mlx_put_image_to_window(mlx, win, img, x, y);
	mlx_destroy_image(mlx, img);
}

void	defin_player(t_xvar *mlx, t_win_list *win, t_core *core)
{
	int	x;
	int	y;

	core->player = malloc(sizeof(t_player));
	core->count_move = 0;
	x = 0;
	y = 0;
	while (y < core->maps->y)
	{
		while (x < core->maps->x)
		{
			if (core->maps->mapsx_y[y][x] == 'P')
			{
				set_player(mlx, win, (x * 40), (y * 40));
				core->player->begin_pos.px = x;
				core->player->begin_pos.py = y;
				core->player->pos.px = x;
				core->player->pos.py = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

t_pos	*get_position(t_maps *maps, char target, int x, int y)
{
	t_pos	*position;

	position = malloc(sizeof(t_pos));
	if (!position)
		return (NULL);
	position->px = 0;
	position->py = 0;
	while (y < maps->y)
	{
		while (x < maps->x)
		{
			if (maps->mapsx_y[y][x] == target)
			{
				position->px = x;
				position->py = y;
				return (position);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (position);
}
