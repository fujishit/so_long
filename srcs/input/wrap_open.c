#include "so_long.h"

int	wrap_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		error_print(OPEN_ERROR);
		return (-1);
	}
	return (fd);
}
