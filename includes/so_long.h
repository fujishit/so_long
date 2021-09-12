#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "sl_error.h"

# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}	t_img;

typedef struct	s_sys
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	t_img	img;
	t_img	player_tex;
	t_img	wall_tex;
	t_img	tile_tex;
}	t_sys;

typedef struct	s_map
{
	char	**map;
	size_t	height;
	size_t	width;
}	t_map;

typedef struct	s_game
{
	t_map	map;
	t_sys	sys;
}	t_game;

int		get_pixel(t_img *img, int x, int y);
void	get_color(t_img *img, int x, int y, int c);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	error_print(int error);
int		tex_input(t_sys *sys);
int		map_input(char *path, t_map *map);
int		draw_tile(char **map, t_img *img, t_img *tile_tex);
void	free_map(t_map *map);

#endif /* SO_LONG_H */
