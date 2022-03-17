#include "so_long.h"

static int	get_height(char *path, size_t *height, char *line, int empty_line)
{
	int		ret_gnl;
	int		fd;

	line = NULL;
	fd = wrap_open(path);
	if (fd == -1)
		return (1);
	ret_gnl = get_next_line(fd, &line);
	while (0 < ret_gnl)
	{
		free(line);
		ret_gnl = get_next_line(fd, &line);
		if (line[0] == '\0')
			empty_line = 1;
		*height = *height + 1;
	}
	free(line);
	close(fd);
	if (ret_gnl == 0 && empty_line == 0)
		return (0);
	else if (ret_gnl == -1)
		error_print(READ_ERROR);
	else if (empty_line == 1)
		error_print(MAP_ERROR);
	return (1);
}

static int	read_map(int fd, char ***map)
{
	char	*line;
	size_t	i;
	int		ret;

	line = NULL;
	i = 0;
	ret = get_next_line(fd, &line);
	while (0 < ret)
	{
		if (line[0] == '\0')
			free(line);
		else
			(*map)[i++] = line;
		ret = get_next_line(fd, &line);
	}
	if (line[0] == '\0')
		free(line);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		error_print(READ_ERROR);
	else if (ret != 0)
		error_print(MAP_ERROR);
	free_reading_map(*map, i);
	return (1);
}

static int	get_map(char *path, size_t height, char ***map)
{
	int		fd;

	fd = wrap_open(path);
	if (fd == -1)
		return (1);
	*map = (char **)malloc(sizeof(char *) * height);
	if (*map == NULL)
	{
		error_print(MALLOC_ERROR);
		return (1);
	}
	(*map)[0] = NULL;
	if (read_map(fd, map) == 1)
		return (1);
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
	char	*line;

	if (extension_check(path, ".ber") == 1)
		return (1);
	map->height = 1;
	if (get_height(path, &map->height, 0, line) == 1)
		return (1);
	if (map->height == 1)
	{
		error_print(MAP_ERROR);
		return (1);
	}
	if (get_map(path, map->height, &map->map) == 1)
		return (1);
	map->width = ft_strlen(map->map[0]);
	return (0);
}
