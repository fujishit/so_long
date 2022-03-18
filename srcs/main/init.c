#include "so_long.h"
#include "sl_config.h"

static void	tex_init(t_sys *sys)
{
	sys->num.num0.image = NULL;
	sys->num.num1.image = NULL;
	sys->num.num2.image = NULL;
	sys->num.num3.image = NULL;
	sys->num.num4.image = NULL;
	sys->num.num5.image = NULL;
	sys->num.num6.image = NULL;
	sys->num.num7.image = NULL;
	sys->num.num8.image = NULL;
	sys->num.num9.image = NULL;
	sys->player_up[0].image = NULL;
	sys->player_up[1].image = NULL;
	sys->player_right[0].image = NULL;
	sys->player_right[1].image = NULL;
	sys->player_left[0].image = NULL;
	sys->player_left[1].image = NULL;
	sys->player_down[0].image = NULL;
	sys->player_down[1].image = NULL;
	sys->collect[0].image = NULL;
	sys->collect[1].image = NULL;
	sys->wall.image = NULL;
	sys->tile.image = NULL;
	sys->goal.image = NULL;
	sys->enemy.image = NULL;
}

static void	sys_init(t_sys *sys)
{
	sys->mlx = NULL;
	sys->win = NULL;
	sys->img.image = NULL;
	sys->win_height = 0;
	sys->win_width = 0;
	sys->pl_dir = KEY_W;
}

void	game_init(t_game *game)
{
	game->count = 0;
	sys_init(&game->sys);
	tex_init(&game->sys);
}
