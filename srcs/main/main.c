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
	sys->win_height += 32;
	sys->win = mlx_new_window(\
		sys->mlx, sys->win_width, sys->win_height, "so_long");
	if (sys->win == NULL)
	{
		error_print(WINDOW_ERROR);
		return (1);
	}
	sys->img.image = mlx_new_image(sys->mlx, sys->win_width, sys->win_height);
	if (sys->img.image == NULL)
	{
		error_print(IMAGE_ERROR);
		return (1);
	}
	sys->img.data = mlx_get_data_addr(\
		sys->img.image, &sys->img.bpp, &sys->img.size_line, &sys->img.endian);
}

	// static size_t n = 0;
	// if (n++ == 1)
	// {
	// 	game->count = 9999999999999;
	// }

static void	draw_enemy(t_sys *sys, int frame, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->enemy)
	{
		draw_tex(&sys->img, &sys->player_up[0], \
		map->enemies[i].en_x * TEX_SIZE, map->enemies[i].en_y * TEX_SIZE);
		i++;
	}
}

static void	draw_player(t_sys *sys, int frame, int n, int i)
{
	if (frame < ANIME_FRAME)
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(&sys->img, &sys->player_up[0], n, i);
		else if (sys->pl_dir == KEY_A)
			draw_tex(&sys->img, &sys->player_left[0], n, i);
		else if (sys->pl_dir == KEY_S)
			draw_tex(&sys->img, &sys->player_down[0], n, i);
		else if (sys->pl_dir == KEY_D)
			draw_tex(&sys->img, &sys->player_right[0], n, i);
	}
	else
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(&sys->img, &sys->player_up[1], n, i);
		else if (sys->pl_dir == KEY_A)
			draw_tex(&sys->img, &sys->player_left[1], n, i);
		else if (sys->pl_dir == KEY_S)
			draw_tex(&sys->img, &sys->player_down[1], n, i);
		else if (sys->pl_dir == KEY_D)
			draw_tex(&sys->img, &sys->player_right[1], n, i);
	}
}

int	game_loop(t_game *game)
{
	static int	frame;

	draw_map(&game->map, &game->sys.img, &game->sys, frame);
	draw_player(&game->sys, frame, game->map.pl_x * TEX_SIZE, game->map.pl_y * TEX_SIZE);
	draw_count(&game->sys, &game->sys.num, game->map.width, game->count);
	draw_enemy(&game->sys, frame, &game->map);
	mlx_put_image_to_window(\
		game->sys.mlx, game->sys.win, game->sys.img.image, 0, 0);
	if (frame == ANIME_FRAME * 2)
		frame = 0;
	frame++;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		error_print(ARG_ERROR);
		return (1);
	}
	if (map_input(argv[1], &game.map) == 1)
		return (1);
	if (map_validate(&game.map) == 1)
		abort_exit(&game.map);	//ここまでエラー確認まる
	mlx_setup(&game.sys, game.map);
	if (tex_input(&game.sys) == 1)
		abort_exit(&game.map);
	game.count = 0;
	mlx_loop_hook(game.sys.mlx, game_loop, &game);
	mlx_hook(game.sys.win, 2, 1L << 0, game_key, &game);
	mlx_hook(game.sys.win, 33, 1L << 17, close_window, &game);
	mlx_loop(game.sys.mlx);
	return (0);
}
