#include "so_long.h"
#include "sl_config.h"

static int	check_collision(t_map *map)
{
	if (map->map[map->pl_y][map->pl_x] == 'C')
	{
		map->map[map->pl_y][map->pl_x] = '0';
		map->item--;
		return (0);
	}
	else if (map->map[map->pl_y][map->pl_x] == 'E' && map->item == 0)
		return (1);
	return (0);
}

static int	chara_move(int keycode, t_map *map)
{
	if (keycode == KEY_W && 0 < map->pl_y &&\
	map->map[map->pl_y - 1][map->pl_x] != '1')
		map->pl_y--;
	else if (keycode == KEY_A && 0 < map->pl_x &&\
	map->map[map->pl_y][map->pl_x - 1] != '1')
		map->pl_x--;
	else if (keycode == KEY_S && map->pl_y < map->height &&\
	map->map[map->pl_y + 1][map->pl_x] != '1')
		map->pl_y++;
	else if (keycode == KEY_D && map->pl_x < map->width &&\
	map->map[map->pl_y][map->pl_x + 1] != '1')
		map->pl_x++;
	else
		return (0);
	return (1);
}

int	game_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (chara_move(keycode, &game->map) == 1)
	{
		game->sys.pl_dir = keycode;
		game->count++;
		ft_putnbr_fd(game->count, 1);
		write(1, "\n", 1);
	}
	enemy_move(&game->map);
	if (check_collision(&game->map) == 1)
		exit(0);
	return (0);
}
