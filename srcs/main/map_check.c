#include "so_long.h"

static int	map_isvalid(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (m->map[y][x] != '1')
			{
				if (y == 0 || y == (m->height - 1))
					return (1);
				else if (x == 0 || x == (m->width - 1))
					return (1);
			}
			x++;
		}
		if (m->map[y][x] == '1')
			return (MAP_ERROR);
		y++;
	}
}

int	map_check(t_map *m, char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (map[y][x] == ' ')
			x++;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' ' && \
				map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P')
				return (1);
			x++;
		}
		y++;
	}
	if (map_isvalid(m) == 1)
		return (1);
	return (0);
}
