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

static void ini_game(t_core core, char *str)
{
	core.maps = builder_maps(str);
	core.mlx = mlx_init();
	core.win = mlx_new_window(core.mlx, (core.maps->x * 40), (core.maps->y * 40), "SO_LONG");
	set_layer(core.mlx, core.win, core.maps);
	defin_watter(core.mlx, core.win, core.maps);
	defin_collect(core.mlx, core.win, core.maps);
	defin_exit(core.mlx, core.win, core.maps);
	defin_player(core.mlx, core.win, &core);
	mlx_hook(core.win, 17, 0, close_window, &core);
  	mlx_hook(core.win, 2, 1L<<0, key_hook, &core);
	mlx_loop(core.mlx);
 	mlx_destroy_window(core.mlx,core.win);
 	mlx_destroy_display(core.mlx);
 	free(core.mlx);
 	free(core.player);
 	free_maps(core.maps);
}
static	int maps_pars(char *maps, int test)
{
	t_maps	*maps_pars;
	t_pos *pos;

	maps_pars = builder_maps(maps);
	pos = get_position(maps_pars, 'P');
	flood_fill(maps_pars->mapsx_y, pos->px, pos->py, '0', 'A');
	if (acces_collect(maps_pars, 'C') == 0)
		{
			ft_printf("%s\n","acces items error");
			test = 0;
		}
	if (acces_collect(maps_pars, 'E') == 0)
		{
			ft_printf("%s\n","acces Exit error");
			test = 0;
		}
	if (maps_pars->exit != 1 || maps_pars->collect < 1 || maps_pars->player != 1 || maps_pars->error == 1)
	{
		ft_printf("%s\n","maps error");
		test = 0;
	}
	free_maps(maps_pars);
	free(pos);
	return (test);
} 

char	give_object(char **maps, int x, int y)
{
	char objet;

	objet = maps[y][x];
	return (objet);
}

/* teste si .ber a faire*/ 

int main(int argc, char *argv[])
{
	t_core	core;
	int test;
	if (argc == 2)
	{
	test = maps_pars(argv[1], 1);
	if (test == 0)
		return (0);
	ini_game(core, argv[1]);
	}
	else
	{
		ft_printf("Error\n");
	}
	
	return 0;
}