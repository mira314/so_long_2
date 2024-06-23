/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:25:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/06/23 07:44:45 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define TEST 10
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/libft/libft.h"

typedef struct s_pos
{
	int	px;
	int	py;
}	t_pos;

typedef struct s_player
{
	t_pos	pos;
	t_pos	begin_pos;
}	t_player;

typedef struct s_maps
{
	int		x;
	int		y;
	char	**mapsx_y;
	int		exit;
	int		collect;
	int		collect_ok;
	int		exit_ok;
	int		player;
	int		error;
}	t_maps;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	t_maps		*maps;
	t_player	*player;
	int			count_move;
}	t_core;

/***************************maps.c*****************/
char	*open_maps(char *ber);
t_maps	*builder_maps(char *ber);
void	see_maps(t_maps *maps);
void	free_maps(t_maps *maps);
/***************************key.c******************/
int		key_hook(int keycode, t_core *core);
int		close_window(t_core *core);
/***************************layer.c******************/
void	set_layer(t_xvar *mlx, t_win_list *win, t_maps *maps);
void	set_water(t_xvar *mlx, t_win_list *win, int x, int y);
void	defin_watter(t_xvar *mlx, t_win_list *win, t_maps *maps);
void	watter_error(t_maps *maps);
void	set_layer_add(t_xvar *mlx, t_win_list *win, int x, int y);
/***************************player.c******************/
void	defin_player(t_xvar *mlx, t_win_list *win, t_core *core);
void	set_player(t_xvar *mlx, t_win_list *win, int x, int y);
t_pos	*get_position(t_maps *maps, char target, int x, int y);
/***************************move.c******************/
void	move_player_up(t_core *core);
void	move_player_down(t_core *core);
void	move_player_right(t_core *core);
void	move_player_left(t_core *core);
/*****************************items.c****************/
void	set_collect(t_xvar *mlx, t_win_list *win, int x, int y);
void	defin_collect(t_xvar *mlx, t_win_list *win, t_maps *maps);
void	set_exit(t_xvar *mlx, t_win_list *win, int x, int y);
void	defin_exit(t_xvar *mlx, t_win_list *win, t_maps *maps);
/**************************** maps_pars.c****************/
void	flood_fill(char **map, int x, int y);
int		acces_collect(t_maps *maps, char target);
char	give_object(char **maps, int x, int y);
#endif
