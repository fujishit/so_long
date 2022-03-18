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
	void		*image;
	char		*data;
	int			size_line;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}	t_img;

typedef struct s_num
{
	t_img	num0;
	t_img	num1;
	t_img	num2;
	t_img	num3;
	t_img	num4;
	t_img	num5;
	t_img	num6;
	t_img	num7;
	t_img	num8;
	t_img	num9;
}	t_num;

typedef struct	s_sys
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	t_img	img;
	t_num	num;
	t_img	player_up[2];
	t_img	player_right[2];
	t_img	player_left[2];
	t_img	player_down[2];
	t_img	collect[2];
	t_img	wall;
	t_img	tile;
	t_img	goal;
	t_img	enemy;
	int		pl_dir;
}	t_sys;

typedef struct	s_enemy
{
	size_t	en_x;
	size_t	en_y;
	int		en_dir;
}	t_enemy;

typedef struct	s_map
{
	char	**map;
	size_t	height;
	size_t	width;
	size_t	pl_x;
	size_t	pl_y;
	size_t	item;
	size_t	enemy;
	t_enemy	*enemies;
}	t_map;

typedef struct	s_game
{
	t_map	map;
	t_sys	sys;
	size_t	count;
}	t_game;

void	error_print(int error);
void	game_init(t_game *game);
int		tex_input(t_sys *sys);
int		map_input(char *path, t_map *map);
void	draw_tex(t_img *img, t_img *tex, int x, int y);
int		game_key(int keycode, t_game *game);
void	draw_count(t_sys *sys, t_num *num, size_t width, size_t count);
int		map_check(t_map *m, char **map);
int		map_validate(t_map *map);
int		draw_map(t_map *map, t_img *img, t_sys *sys, int frame);
void	draw_collect(t_sys *sys, int frame, int n, int i);
void	draw_player(t_sys *sys, int frame, int n, int i);
void	draw_enemy(t_sys *sys, int frame, t_map *map);
void	draw_count(t_sys *sys, t_num *num, size_t width, size_t count);
void	enemy_move(t_map *map);
void	free_map(t_map *map);
void	free_reading_map(char **map, size_t height);
void	free_enemy(t_map *map);
void	destroy_texture(t_sys *sys);

void	success_exit(t_sys *sys, t_map *map);
void	map_error_exit(t_map *map);
void	mlx_error_exit(t_sys *sys, t_map *map);

#endif /* SO_LONG_H */
