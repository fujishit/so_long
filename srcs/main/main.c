#include "so_long.h"
#include "sl_config.h"

int	close_window(int keycode, t_game *game)
{
	exit(0);
}

int	mlx_setup(t_sys *sys, t_map map)
{
	sys->mlx = mlx_init();
	if (sys->mlx == NULL)
	{
		error_print(MLX_ERROR);
		return (1);
	}
	sys->win_height = map.height * TEX_SIZE;
	sys->win_width = map.width * TEX_SIZE;
	// debug
	printf("window: height = %d, width = %d\n", sys->win_height, sys->win_width);
	sys->win = mlx_new_window(sys->mlx, sys->win_width, sys->win_height, "so_long");
	if (sys->win == NULL)
	{
		error_print(WINDOW_ERROR);
		return (1);
	}
	sys->img.img = mlx_new_image(sys->mlx, sys->win_width, sys->win_height);
	if (sys->img.img == NULL)
	{
		error_print(IMAGE_ERROR);
		return (1);
	}
	sys->img.addr = (int *)mlx_get_data_addr(\
		sys->img.img, &sys->img.bpp, &sys->img.size_l, &sys->img.endian);
}

int	game_loop(t_game *game)
{
	draw_tile(game->map.map, &game->sys.img, &game->sys.tile_tex);
	mlx_put_image_to_window(\
		game->sys.mlx, game->sys.win, game->sys.img.img, 0, 0);
}

int	game_key(int keycode, t_game *game)
{
	// if (keycode == KEY_W)
	// else if (keycode == KEY_A)
	// else if (keycode == KEY_S)
	// else if (keycode == KEY_D)
	if (keycode == KEY_ESC)
		exit(0);
}

// int	main(int argc, char *argv[])
// {
// 	t_game	game;

// 	if (argc != 2)
// 	{
// 		error_print(ARG_ERROR);
// 		return (1);
// 	}
// 	if (map_input(argv[1], &game.map) == 1)
// 		return (1);
// 	mlx_setup(&game.sys, game.map);
// 	if (tex_input(&game.sys) == 1)
// 		return (1);
// 	// if (validate_map() == 1)
// 		// return (1);
// 	mlx_loop_hook(game.sys.mlx, game_loop, &game);
// 	mlx_hook(game.sys.win, 2, 1L << 0, game_key, &game);
// 	mlx_hook(game.sys.win, 33, 1L << 17, close_window, &game);
// 	mlx_loop(game.sys.mlx);
// 	return (0);
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 200, 200, "Hello world!");
	img.img = mlx_new_image(mlx, 200, 200);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_l,
								&img.endian);
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	my_mlx_pixel_put(&img, 1, 1, 0x00FF0000);
	my_mlx_pixel_put(&img, 2, 1, 0x00FF0000);
	my_mlx_pixel_put(&img, 3, 1, 0x00FF0000);
	my_mlx_pixel_put(&img, 4, 1, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 1, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L << 0, game_key, NULL);
	mlx_hook(mlx_win, 33, 1L << 17, close_window, NULL);
	mlx_loop(mlx);
}
