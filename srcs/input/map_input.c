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
	if (ret_gnl == 0)
		return (0);
	else if (ret_gnl == -1)
		error_print(READ_ERROR);
	else if (ret_gnl != 0)
		error_print(MAP_ERROR);
	return (1);
}

static int	get_map(char *path, size_t height, char ***map)
{
	int		fd;
	size_t	i;

	fd = wrap_open(path);
	if (fd == -1)
		return (1);
	*map = (char **)malloc(sizeof(char *) * (height + 1));
	(*map)[height] = NULL;
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
	return (0);
}

static int	extension_check(char *filepath, char *extension)
{
	size_t	file_len;
	size_t	ext_len;

	file_len = ft_strlen(filepath);
	ext_len = ft_strlen(extension);
	if (file_len < ext_len)
	{
		error_print(EXTENSION_ERROR);
		return (1);
	}
	while (extension[ext_len] == filepath[file_len])
	{
		if (ext_len == 0)
			return (0);
		ext_len--;
		file_len--;
	}
	error_print(EXTENSION_ERROR);
	return (1);
}

int	map_input(char *path, t_map *map)
{
	if (extension_check(path, ".ber") == 1)
		return (1);
	if (get_height(path, &map->height) == 1)
		return (1);
	if (get_map(path, map->height, &map->map) == 1)
	{
		free_map(map);
		error_print(MAP_ERROR);
		return (1);
	}
	map->width = ft_strlen(map->map[0]);
}

	// debug
	// printf("map: height = [%ld], width = [%ld]\n", map->height, map->width);
	// for (int i = 0; i < map->height; i++)
	// 	printf("[%s]\n", map->map[i]);
