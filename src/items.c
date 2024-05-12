/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:30:33 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/24 09:32:26 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void    set_collect(t_xvar *mlx, t_win_list *win, int x, int y)
{
    void *img;
    int W;
    int H;

    img = mlx_xpm_file_to_image(mlx, "font/collect_15-40x40.xpm", &W, &H);

    mlx_put_image_to_window(mlx, win, img, x, y);
    mlx_destroy_image(mlx, img);
}

void defin_collect(t_xvar *mlx, t_win_list *win, t_maps *maps)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < maps->y)
    {
        while (x < maps->x)
        {
            if (maps->mapsx_y[y][x] == 'C')
            {
               set_collect(mlx, win, (x * 40) ,(y * 40));
            }
            x++;
        }
        x = 0;
        y++;
    }
}
void    set_exit(t_xvar *mlx, t_win_list *win, int x, int y)
{
    void *img;
    int W;
    int H;

    img = mlx_xpm_file_to_image(mlx, "font/sofa_15-40x40.xpm", &W, &H);

    mlx_put_image_to_window(mlx, win, img, x, y);
    mlx_destroy_image(mlx, img);
}
void defin_exit(t_xvar *mlx, t_win_list *win, t_maps *maps)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < maps->y)
    {
        while (x < maps->x)
        {
            if (maps->mapsx_y[y][x] == 'E')
            {
               set_exit(mlx, win, (x * 40) ,(y * 40));
            }
            x++;
        }
        x = 0;
        y++;
    }
}