#include "so_long.h"
#include "sl_error.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map);
}
