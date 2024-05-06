/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:01:49 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/24 09:54:22 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int main(void)
{
	t_core	core;
	core.maps = builder_maps("maps/wall_only.ber");

	see_maps(core.maps);
	core.mlx = mlx_init();
	core.win = mlx_new_window(core.mlx, (core.maps->x * 40), (core.maps->y * 40), "SO_LONG");
	set_layer(core.mlx, core.win, core.maps);
	defin_player(core.mlx, core.win, &core);
	defin_watter(core.mlx, core.win, core.maps);
	defin_collect(core.mlx, core.win, core.maps);
	defin_exit(core.mlx, core.win, core.maps);
	mlx_hook(core.win, 17, 0, close_window, &core);
  mlx_hook(core.win, 2, 1L<<0, key_hook, &core);

	mlx_loop(core.mlx);
 	mlx_destroy_window(core.mlx,core.win);
 	mlx_destroy_display(core.mlx);
 	see_maps(core.maps);
 	free(core.mlx);
 	free(core.player);
 	free_maps(core.maps);
	return 0;
}