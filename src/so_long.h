/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:25:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/24 09:55:06 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define TEST 10
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include "../lib/libft/libft.h"

typedef struct s_pos
{
	size_t	px;
	size_t	py;
}				t_pos;

typedef struct s_player 
{
	t_pos pos;
	t_pos begin_pos;
}				t_player;


typedef	struct	s_maps
{
  int  x;
  int  y;
  char  **mapsx_y;
  int exit_ok;
  int collect_ok;
}				t_maps;

typedef	struct	s_core
{
	void *mlx;
  void *win;
  t_maps *maps;
}
				t_core;
/***************************maps.c*****************/
char	*open_maps(char *ber);
/***************************key.c******************/
int key_hook(int keycode, t_core *core);
int close_window(t_core *core);
#endif