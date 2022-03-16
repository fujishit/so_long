#include "sl_error.h"
#include <unistd.h>

void	error_print(int error)
{
	write(1, "Error\n", 6);
	if (error == MALLOC_ERROR)
		write(1, "Memory allocation error.\n", 25);
	else if (error == OPEN_ERROR)
		write(1, "Can't open file.\n", 17);
	else if (error == READ_ERROR)
		write(1, "Can't read file.\n", 17);
	else if (error == MAP_ERROR)
		write(1, "Invalid map.\n", 13);
	else if (error == EXTENSION_ERROR)
		write(1, "Please *.ber file.\n", 19);
	else if (error == ARG_ERROR)
		write(1, "Invalid arguments.\n", 19);
	else if (error == MLX_ERROR)
		write(1, "mlx init error.\n", 16);
	else if (error == WINDOW_ERROR)
		write(1, "mlx window error.\n", 18);
	else if (error == IMAGE_ERROR)
		write(1, "mlx image error.\n", 17);
	else if (error == XPM_LOAD_ERROR)
		write(1, "mlx xpm load error.\n", 20);
}
