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
}
