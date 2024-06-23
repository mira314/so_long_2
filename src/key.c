/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:26:31 by vrandria          #+#    #+#             */
/*   Updated: 2024/06/23 07:18:39 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	close_window(t_core *core)
{
	mlx_loop_end(core->mlx);
	return (0);
}

int	key_hook(int keycode, t_core *core)
{
	if (keycode == 65307)
	{
		close_window(core);
	}
	if (keycode == 119 || keycode == 65362)
		move_player_up(core);
	if (keycode == 115 || keycode == 65364)
		move_player_down(core);
	if (keycode == 97 || keycode == 65361)
		move_player_left(core);
	if (keycode == 100 || keycode == 65363)
		move_player_right(core);
	return (0);
}
