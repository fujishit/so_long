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
	char		*addr;
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
	t_img	player_up[2];
	t_img	player_right[2];
	t_img	player_left[2];
	t_img	player_down[2];
	t_img	collect[2];
	t_img	wall;
	t_img	tile;
	t_img	goal;
	int		pl_dir;
}	t_sys;

typedef struct	s_map
{
	char	**map;
	size_t	height;
	size_t	width;
	size_t	pl_x;
	size_t	pl_y;
}	t_map;

typedef struct	s_game
{
	t_map	map;
	t_sys	sys;
	size_t	count;
}	t_game;

void	error_print(int error);
int		tex_input(t_sys *sys);
int		map_input(char *path, t_map *map);
void	draw_tex(t_img *img, t_img *tex, int x, int y);
int		game_key(int keycode, t_game *game);
int		map_validate(t_map *map);
int		draw_map(t_map *map, t_img *img, t_sys *sys, int frame);
void	free_map(t_map *map);

#endif /* SO_LONG_H */
