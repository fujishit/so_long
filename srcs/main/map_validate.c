#include "so_long.h"
#include "sl_config.h"

static int	get_pl(t_map *map)
{
	size_t	i;
	size_t	n;

	i = 0;
	map->pl_y = 1;
	map->pl_x = 1;
	while (i < map->height)
	{
		n = 0;
		while (n < map->width)
		{
			if (map->map[i][n] == 'P')
			{
				map->pl_y = i;
				map->pl_x = n;
			}
			n++;
		}
		i++;
	}
	return (0);
}

static void	get_item_num(t_map *map, size_t *item)
{
	size_t	i;
	size_t	n;
	size_t	num;

	i = 0;
	num = 0;
	while (i < map->height)
	{
		n = 0;
		while (n < map->width)
		{
			if (map->map[i][n] == 'C')
				num++;
			n++;
		}
		i++;
	}
	*item = num;
}

static int	multiple_check(t_map *map, char c)
{
	size_t	y;
	size_t	x;
	size_t	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (c == map->map[y][x])
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

static int	get_enemy(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	count;

	map->enemy = multiple_check(map, 'R');
	map->enemies = (t_enemy *)malloc(sizeof(t_enemy) * (map->enemy + 1));
	if (map->enemies == NULL)
		return (1);
	y = 0;
	count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'R')
			{
				map->enemies[count].en_y = y;
				map->enemies[count].en_x = x;
				map->enemies[count].en_dir = KEY_S;
				count++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	map_validate(t_map *map)
{
	if (get_enemy(map) == 1)
	{
		error_print(MAP_ERROR);
		return (1);
	}
	if (get_pl(map) == 1)
	{
		error_print(MAP_ERROR);
		return (1);
	}
	if (multiple_check(map, 'E') == 0 || \
		multiple_check(map, 'P') != 1 || \
		multiple_check(map, 'C') == 0)
	{
		error_print(MAP_ERROR);
		return (1);
	}
	if (map_check(map, map->map) == 1)
	{
		error_print(MAP_ERROR);
		return (1);
	}
	get_item_num(map, &map->item);
	return (0);
}
