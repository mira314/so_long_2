/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:24:27 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/23 08:49:15 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_layer(t_xvar *mlx, t_win_list *win, t_maps *maps)
{
    void *img;
    int W;
    int H;
    int x;
    int y;

    x = 0;
    y = 0;
    img = mlx_xpm_file_to_image(mlx, "font/Tile_15_40x40.xpm", &W, &H);
    while(y < maps->y)
    {
    	x = 0;
    	while (x < maps->x)
    	{
    		mlx_put_image_to_window(mlx, win, img, (x * 40), (y * 40));
    		x += 1;
    	}
    	y += 1;
    }
    mlx_destroy_image(mlx, img);
}

void    set_water(t_xvar *mlx, t_win_list *win, int x, int y)
{
    void *img;
    int W;
    int H;

    img = mlx_xpm_file_to_image(mlx, "font/Elements_20_40X40.xpm", &W, &H);

    mlx_put_image_to_window(mlx, win, img, x, y);
    mlx_destroy_image(mlx, img);
}

void    set_layer_add(t_xvar *mlx, t_win_list *win, int x, int y)
{
    void *img;
    int W;
    int H;

    img = mlx_xpm_file_to_image(mlx, "font/Tile_15_40x40.xpm", &W, &H);

    mlx_put_image_to_window(mlx, win, img, x, y);
    mlx_destroy_image(mlx, img);
}

void defin_watter(t_xvar *mlx, t_win_list *win, t_maps *maps)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < maps->y)
    {
        while (x < maps->x)
        {
            if (maps->mapsx_y[y][x] == '1')
            {
               set_water(mlx, win, (x * 40) ,(y * 40));
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void watter_error(t_maps *maps)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < maps->x)
    {
        if (maps->mapsx_y[0][x] == '0' || maps->mapsx_y[maps->y - 1][x] == '0')
        {
            maps->error = 1;
            break;
        }
        x++;
    }
    while (y < maps->y)
    {
        if (maps->mapsx_y[y][0] == '0' || maps->mapsx_y[y][maps->x - 1] == '0')
        {
            maps->error = 1;
            break ;
        }
        y++;
    }
}
