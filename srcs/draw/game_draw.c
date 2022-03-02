#include "so_long.h"
#include "sl_config.h"

static void	draw_player(t_sys *sys, int frame, int n, int i)
{
	if (frame < ANIME_FRAME)
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
	if (frame < ANIME_FRAME)
		draw_tex(&sys->img, &sys->collect[0], n, i);
	else
		draw_tex(&sys->img, &sys->collect[1], n, i);
}

static t_img	*select_number(size_t num, t_num *nums)
{
	while (10 <= num)
	{
		num = num % 10;
	}
	if (num == 0)
		return (&nums->num0);
	else if (num == 1)
		return (&nums->num1);
	else if (num == 2)
		return (&nums->num2);
	else if (num == 3)
		return (&nums->num3);
	else if (num == 4)
		return (&nums->num4);
	else if (num == 5)
		return (&nums->num5);
	else if (num == 6)
		return (&nums->num6);
	else if (num == 7)
		return (&nums->num7);
	else if (num == 8)
		return (&nums->num8);
	else if (num == 9)
		return (&nums->num9);
}

void	draw_count(t_sys *sys, t_num *num, size_t width, size_t count)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = 1;
	while (i < width)
	{
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	while (0 < i)
	{
		draw_tex(&sys->img, select_number(count / temp, num), \
			sys->win_width - (i * TEX_SIZE), sys->win_height - 32);
		count = count % temp;
		temp = temp / 10;
		i--;
	}
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
