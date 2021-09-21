#include "so_long.h"
#include "sl_config.h"

static int	check_collision(t_map *map)
{
	if (map->map[map->pl_y][map->pl_x] == 'C')
		map->map[map->pl_y][map->pl_x] = '0';
	else if (map->map[map->pl_y][map->pl_x] == 'E')
		return (1);
}

int	game_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	game->sys.pl_dir = keycode;
	game->count++;
	printf("%d steps\n", game->count);
	if (keycode == KEY_W && 0 < game->map.pl_y &&\
	game->map.map[game->map.pl_y - 1][game->map.pl_x] != '1')
		game->map.pl_y--;
	else if (keycode == KEY_A && 0 < game->map.pl_x &&\
	game->map.map[game->map.pl_y][game->map.pl_x - 1] != '1')
		game->map.pl_x--;
	else if (keycode == KEY_S && game->map.pl_y < game->map.height &&\
	game->map.map[game->map.pl_y + 1][game->map.pl_x] != '1')
		game->map.pl_y++;
	else if (keycode == KEY_D && game->map.pl_x < game->map.width &&\
	game->map.map[game->map.pl_y][game->map.pl_x + 1] != '1')
		game->map.pl_x++;
	if (check_collision(&game->map) == 1)
		exit(0);
	return (0);
}
