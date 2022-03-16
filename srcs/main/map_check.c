#include "so_long.h"

static int	map_isvalid(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < m->width)
	{
		if (m->map[0][x] != '1')
			return (1);
		else if (m->map[m->height - 1][x] != '1')
			return (1);
		x++;
	}
	while (y < m->height)
	{
		if (m->map[y][0]  != '1')
			return (1);
		else if (m->map[y][m->width - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

#ifdef BONUS

static int	chr_isvalid(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'P')
		return (0);
	else if (c == 'R')
		return (0);
	return (1);
}

#else

static int	chr_isvalid(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'P')
		return (0);
	return (1);
}

#endif

int	map_check(t_map *m, char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (chr_isvalid(map[y][x]) == 1)
				return (1);
			x++;
		}
		y++;
	}
	if (map_isvalid(m) == 1)
		return (1);
	return (0);
}
