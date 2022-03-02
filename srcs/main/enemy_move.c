#include "so_long.h"

#ifdef BONUS

void	enemy_move(t_map *map)
{
	printf("test\n");
}

#else

void	enemy_move(t_map *map)
{
	(void)map;
	return ;
}

#endif
