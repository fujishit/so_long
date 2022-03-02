#include "so_long.h"
#include "sl_config.h"

static void	en_dir(t_map *map, t_enemy *enemy)
{
	int	flag;
	int	x_diff;
	int	y_diff;

	if (enemy->en_x < map->pl_x)
		x_diff = map->pl_x - enemy->en_x;
	else
		x_diff = enemy->en_x - map->pl_x;
	if (enemy->en_y < map->pl_y)
		y_diff = map->pl_y - enemy->en_y;
	else
		y_diff = enemy->en_y - map->pl_y;
	if (map->pl_y < map->pl_x)
		flag = 0;
	else
		flag = 1;
	if (flag == 0 && enemy->en_x < map->pl_x)
		enemy->en_dir = KEY_D;
	else if (flag == 0 && map->pl_x < enemy->en_x)
		enemy->en_dir = KEY_A;
	else if (flag == 1 && enemy->en_y < map->pl_y)
		enemy->en_dir = KEY_W;
	else if (flag == 1 && map->pl_y < enemy->en_y)
		enemy->en_dir = KEY_S;
}

static void	en_move(t_map *map, t_enemy *enemy)
{
	if (enemy->en_dir == KEY_W && map->map[enemy->en_y + 1][enemy->en_x] != '1')
		enemy->en_y++;
	else if (enemy->en_dir == KEY_S && \
		map->map[enemy->en_y - 1][enemy->en_x] != '1')
		enemy->en_y--;
	else if (enemy->en_dir == KEY_D && \
		map->map[enemy->en_y][enemy->en_x + 1] != '1')
		enemy->en_x++;
	else if (enemy->en_dir == KEY_A && \
		map->map[enemy->en_y][enemy->en_x - 1] != '1')
		enemy->en_x--;
}

void	enemy_move(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->enemy)
	{
		en_dir(map, map->enemys);
		en_move(map, map->enemys);
		i++;
	}
	return ;
}
