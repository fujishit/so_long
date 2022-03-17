#include "so_long.h"

void	success_exit(t_sys *sys, t_map *map)
{
	free_map(map);
	free_enemy(map);
	destroy_texture(sys);
	mlx_destroy_window(sys->mlx, sys->win);
	mlx_destroy_display(sys->mlx);
	free(sys->mlx);
	exit(0);
}


void	map_error_exit(t_map *map)
{
	free_map(map);
	free_enemy(map);
	exit(1);
}

void	mlx_error_exit(t_sys *sys, t_map *map)
{
	free_map(map);
	free_enemy(map);
	destroy_texture(sys);
	if (sys->win != NULL)
		mlx_destroy_window(sys->mlx, sys->win);
	if (sys->mlx != NULL)
		mlx_destroy_display(sys->mlx);
	free(sys->mlx);
	exit(0);	
}
