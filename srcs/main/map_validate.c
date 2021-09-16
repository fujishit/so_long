#include "so_long.h"

static void	get_pl(char **map, size_t *pl_y, size_t *pl_x)
{
	int	i;
	int	n;

	i = 0;
	while (map[i] != NULL)
	{
		n = 0;
		while (map[i][n] != '\0')
		{
			if (map[i][n] == 'P')
			{
				*pl_y = i;
				*pl_x = n;
			}
			n++;
		}
		i++;
	}
}

int	map_validate(t_map *map)
{
	get_pl(map->map, &map->pl_y, &map->pl_x);
	return (0);
}
