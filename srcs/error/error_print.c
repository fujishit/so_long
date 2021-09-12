#include "sl_error.h"

void	error_print(int error)
{
	printf("Error\n");
	if (error == MALLOC_ERROR)
		printf("Memory allocation error.\n");
	else if (error == OPEN_ERROR)
		printf("Can't open file.\n");
	else if (error == READ_ERROR)
		printf("Can't read file.\n");
	else if (error == MAP_ERROR)
		printf("Invalid map.\n");
	else if (error == EXTENSION_ERROR)
		printf("Please *.ber file.\n");
	else if (error == ARG_ERROR)
		printf("Invalid arguments.\n");
	else if (error == MLX_ERROR)
		printf("mlx init error.\n");
	else if (error == WINDOW_ERROR)
		printf("mlx window error.\n");
	else if (error == IMAGE_ERROR)
		printf("mlx image error.\n");
	else if (error == XPM_LOAD_ERROR)
		printf("mlx xpm load error.\n");
}
