#include "so_long.h"

void	success_exit(t_sys *sys, t_map *map)
{
	free_map(map);
	free_enemy(map);
	exit(0);
}


void	abort_exit(t_map *map)
{
	free_map(map);
	exit(1);
}
