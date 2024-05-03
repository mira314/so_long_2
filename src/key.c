/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:26:31 by vrandria          #+#    #+#             */
/*   Updated: 2024/04/21 11:29:40 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int close_window(t_core *core)
{
    mlx_loop_end(core->mlx);
    return 0;
}

int key_hook(int keycode, t_core *core)
{
	ft_printf("%d\n", keycode);
    if (keycode == 65307)
    {
        close_window(core);
    }
    return 0;
}
