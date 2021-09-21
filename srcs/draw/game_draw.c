#include "so_long.h"
#include "sl_config.h"

static void	draw_player(t_sys *sys, int frame, int n, int i)
{
	if (frame < 200)
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(&sys->img, &sys->player_up[0], n, i);
		else if (sys->pl_dir == KEY_A)
			draw_tex(&sys->img, &sys->player_left[0], n, i);
		else if (sys->pl_dir == KEY_S)
			draw_tex(&sys->img, &sys->player_down[0], n, i);
		else if (sys->pl_dir == KEY_D)
			draw_tex(&sys->img, &sys->player_right[0], n, i);
	}
	else
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(&sys->img, &sys->player_up[1], n, i);
		else if (sys->pl_dir == KEY_A)
			draw_tex(&sys->img, &sys->player_left[1], n, i);
		else if (sys->pl_dir == KEY_S)
			draw_tex(&sys->img, &sys->player_down[1], n, i);
		else if (sys->pl_dir == KEY_D)
			draw_tex(&sys->img, &sys->player_right[1], n, i);
	}
}

static void	draw_collect(t_sys *sys, int frame, int n, int i)
{
	if (frame < 200)
		draw_tex(&sys->img, &sys->collect[0], n, i);
	else
		draw_tex(&sys->img, &sys->collect[1], n, i);
}

int	draw_map(t_map *map, t_img *img, t_sys *sys, int frame)
{
	int			i;
	int			n;

	i = 0;
	while (map->map[i] != NULL)
	{
		n = 0;
		while (map->map[i][n] != '\0')
		{
			draw_tex(img, &sys->tile, n * TEX_SIZE, i * TEX_SIZE);
			if (map->map[i][n] == '1')
				draw_tex(img, &sys->wall, n * TEX_SIZE, i * TEX_SIZE);
			else if (map->map[i][n] == 'C')
				draw_collect(sys, frame, n * TEX_SIZE, i * TEX_SIZE);
			else if (map->pl_y == i && map->pl_x == n)
				draw_player(sys, frame, n * TEX_SIZE, i * TEX_SIZE);
			else if (map->map[i][n] == 'E')
				draw_tex(img, &sys->goal, n * TEX_SIZE, i * TEX_SIZE);
			n++;
		}
		i++;
	}
}
