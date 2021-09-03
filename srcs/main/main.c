#include "so_long.h"

int	validate_map(void)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	map_input(argv[1], &game.map);
	if (validate_map() == 1)
	{
		error_print(MAP_ERROR);
		return (1);
	}
	return (0);
}
