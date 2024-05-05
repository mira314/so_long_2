#include "so_long.h"

static void	move_helps(t_core *core, t_pos spot, int x, int y)
{
	set_player(core->mlx, core->win, ((spot.px + x) * 40), ((spot.py + y) * 40));
	core->maps->mapsx_y[spot.py][spot.px] = '0';
	core->maps->mapsx_y[spot.py + y][spot.px + x] = 'P';
	set_layer_add(core->mlx, core->win, (spot.px * 40), (spot.py * 40));
	core->player->pos.px += x;
	core->player->pos.py += y;
	core->count_move += 1;
	ft_printf("Move %d \n", core->count_move);
}

void	move_player_up(t_core *core)
{
	t_pos spot;

	spot.px = core->player->pos.px;
	spot.py = core->player->pos.py;
	if (core->maps->mapsx_y[spot.py - 1][spot.px] == '0')
		move_helps(core, spot, 0, -1);
	else if(core->maps->mapsx_y[spot.py - 1][spot.px] == 'C')
		{
			move_helps(core,spot, 0, -1);
			core->maps->collect -= 1;
		}
	else if(core->maps->mapsx_y[spot.py - 1][spot.px] == 'E' && \
			core->maps->collect == 0)
	{
		move_helps(core,spot, 0, -1);
		close_window(core);
		ft_printf("%s\n","YOU WIN");
	}
}

void	move_player_down(t_core *core)
{
	t_pos spot;

	spot.px = core->player->pos.px;
	spot.py = core->player->pos.py;
	if (core->maps->mapsx_y[spot.py + 1][spot.px] == '0')
		move_helps(core, spot, 0, 1);
	else if(core->maps->mapsx_y[spot.py + 1][spot.px] == 'C')
		{
			move_helps(core,spot, 0, 1);
			core->maps->collect -= 1;
		}
	else if(core->maps->mapsx_y[spot.py + 1][spot.px] == 'E' && \
			core->maps->collect == 0)
	{
		move_helps(core,spot, 0, 1);
		close_window(core);
		ft_printf("%s\n","YOU WIN");
	}
}

void	move_player_left(t_core *core)
{
	t_pos spot;

	spot.px = core->player->pos.px;
	spot.py = core->player->pos.py;
	if (core->maps->mapsx_y[spot.py][spot.px - 1] == '0')
		move_helps(core, spot, -1, 0);
	else if(core->maps->mapsx_y[spot.py][spot.px - 1] == 'C')
		{
			move_helps(core,spot, -1, 0);
			core->maps->collect -= 1;
		}
	else if(core->maps->mapsx_y[spot.py][spot.px - 1] == 'E' && \
			core->maps->collect == 0)
	{
		move_helps(core,spot, -1, 0);
		close_window(core);
		ft_printf("%s\n","YOU WIN");
	}
}

void	move_player_right(t_core *core)
{
	t_pos spot;

	spot.px = core->player->pos.px;
	spot.py = core->player->pos.py;
	if (core->maps->mapsx_y[spot.py][spot.px + 1] == '0')
		move_helps(core, spot, 1, 0);
	else if(core->maps->mapsx_y[spot.py][spot.px + 1] == 'C')
		{
			move_helps(core,spot, 1, 0);
			core->maps->collect -= 1;
		}
	else if(core->maps->mapsx_y[spot.py][spot.px + 1] == 'E' && \
			core->maps->collect == 0)
	{
		move_helps(core,spot, 1, 0);
		close_window(core);
		ft_printf("%s\n","YOU WIN");
	}
}
