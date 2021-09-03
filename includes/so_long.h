#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "sl_error.h"

# include <fcntl.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define TEX_SIZE 80
# define WALL "./texture/wall.xpm"
# define ITEM "./texture/item.xpm"

typedef struct	s_sys
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
}	t_sys;

typedef struct	s_map
{
	char	**map;
	size_t	height;
	size_t	width;
}	t_map;

typedef struct	s_game
{
	t_map	*map;
}	t_game;

void	error_print(int error);
void	map_input(char *path, t_map **map);
void	free_map(t_map *map);

#endif /* SO_LONG_H */
