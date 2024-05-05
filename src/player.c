/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:59:08 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/24 09:39:24 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void    set_player(t_xvar *mlx, t_win_list *win, int x, int y)
{
    void *img;
    int W;
    int H;

    img = mlx_xpm_file_to_image(mlx, "font/cat_f.xpm", &W, &H);

    mlx_put_image_to_window(mlx, win, img, x, y);
    mlx_destroy_image(mlx, img);
}

void defin_player(t_xvar *mlx, t_win_list *win, t_core *core)
{
    int x;
    int y;

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
               set_player(mlx, win, (x * 40) ,(y * 40));
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