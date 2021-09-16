#include "so_long.h"
#include "sl_config.h"

static void	draw_player_2(t_img *img, t_sys *sys, int n, int i)
{
	if (sys->pl_dir == KEY_W)
		draw_tex(img, &sys->player_up[1], n * TEX_SIZE, i * TEX_SIZE);
	else if (sys->pl_dir == KEY_A)
		draw_tex(img, &sys->player_left[1], n * TEX_SIZE, i * TEX_SIZE);
	else if (sys->pl_dir == KEY_S)
		draw_tex(img, &sys->player_down[1], n * TEX_SIZE, i * TEX_SIZE);
	else if (sys->pl_dir == KEY_D)
		draw_tex(img, &sys->player_right[1], n * TEX_SIZE, i * TEX_SIZE);
}

static void	draw_player(t_img *img, t_sys *sys, int n, int i)
{
	static int	frame;

	if (frame < 200)
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(img, &sys->player_up[0], n * TEX_SIZE, i * TEX_SIZE);
		else if (sys->pl_dir == KEY_A)
			draw_tex(img, &sys->player_left[0], n * TEX_SIZE, i * TEX_SIZE);
		else if (sys->pl_dir == KEY_S)
			draw_tex(img, &sys->player_down[0], n * TEX_SIZE, i * TEX_SIZE);
		else if (sys->pl_dir == KEY_D)
			draw_tex(img, &sys->player_right[0], n * TEX_SIZE, i * TEX_SIZE);
	}
	else
		draw_player_2(img, sys, n, i);
	if (frame == 400)
		frame = 0;
	frame++;
}

static void	draw_collect(t_img *img, t_sys *sys, int n, int i)
{
	static int	frame;

	if (frame < 200)
		draw_tex(img, &sys->collect[0], n * TEX_SIZE, i * TEX_SIZE);
	else
		draw_tex(img, &sys->collect[1], n * TEX_SIZE, i * TEX_SIZE);
	if (frame == 400)
		frame = 0;
	frame++;
}

int	draw_map(t_map *map, t_img *img, t_sys *sys)
{
	int	i;
	int	n;

	i = 0;
	while (map->map[i] != NULL)
	{
		n = 0;
		while (map->map[i][n] != '\0')
		{
			draw_tex(img, &sys->tile, n * TEX_SIZE, i * TEX_SIZE);
			if (map->map[i][n] == '1')
				draw_tex(img, &sys->wall, n * TEX_SIZE, i * TEX_SIZE);
			if (map->map[i][n] == 'C')
				draw_collect(img, sys, n, i);
			if (map->pl_y == i && map->pl_x == n)
				draw_player(img, sys, n, i);
			if (map->map[i][n] == 'E')
				draw_tex(img, &sys->wall, n * TEX_SIZE, i * TEX_SIZE);
			n++;
		}
		i++;
	}
}
