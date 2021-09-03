#include "so_long.h"

static int	wrap_open(char *path)
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

static int	get_height(char *path, size_t *height)
{
	int		ret_gnl;
	int		fd;
	char	*line;

	*height = 1;
	fd = wrap_open(path);
	if (fd == -1)
		return (1);
	ret_gnl = get_next_line(fd, &line);
	while (0 < ret_gnl && line[0] != '\0')
	{
		free(line);
		ret_gnl = get_next_line(fd, &line);
		if (line[0] != '\0')
			*height = *height + 1;
	}
	free(line);
	close(fd);
	if (ret_gnl != 0)
	{
		error_print(READ_ERROR);
		return (1);
	}
	return (0);
}

static int	get_map(char *path, size_t height, char ***map)
{
	int		fd;
	size_t	i;

	fd = wrap_open(path);
	if (fd == -1)
		return (1);
	*map = (char **)malloc(sizeof(char *) * (height + 1));
	if (*map == NULL)
	{
		error_print(MALLOC_ERROR);
		return (1);
	}
	i = 0;
	while (i < height)
	{
		if (get_next_line(fd, &((*map)[i])) == -1)
		{
			error_print(READ_ERROR);
			return (1);
		}
		i++;
	}
	map[i] = NULL;
	return (0);
}

static size_t	get_width(char *map)
{
	return (ft_strlen(map));
}

void	map_input(char *path, t_map **map)
{
	*map = (t_map *)malloc(sizeof(map));
	if (*map == NULL)
	{
		error_print(MALLOC_ERROR);
		exit(1);
	}
	if (get_height(path, &(*map)->height) == 1)
	{
		free(*map);
		exit(1);
	}
	if (get_map(path, (*map)->height, &(*map)->map) == 1)
	{
		free_map(*map);
		exit(1);
	}
	(*map)->width = get_width((*map)->map[0]);
	printf("height = [%ld], width = [%ld]\n", (*map)->height, (*map)->width);
	for (int i = 0; i < (*map)->height; i++)
		printf("[%s]\n", (*map)->map[i]);
}
