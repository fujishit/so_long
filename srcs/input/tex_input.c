#include "so_long.h"
#include "sl_config.h"

static int	tex_load(t_img *tex, void *mlx, char *path)
{
	tex->img = mlx_xpm_file_to_image(\
		mlx, path, &tex->img_width, &tex->img_height);
	if (tex->img == NULL)
	{
		error_print(XPM_LOAD_ERROR);
		return (1);
	}
	tex->addr = mlx_get_data_addr(\
		tex->img, &tex->bpp, &tex->size_l, &tex->endian);
	if (tex->addr == NULL)
	{
		error_print(MLX_ERROR);
		return (1);
	}
	return (0);
}

static int	input_player(t_sys *sys)
{
	if (tex_load(&sys->player_up[0], sys->mlx, PLAYER_UP1) == 1)
		return (1);
	else if (tex_load(&sys->player_up[1], sys->mlx, PLAYER_UP2) == 1)
		return (1);
	else if (tex_load(&sys->player_right[0], sys->mlx, PLAYER_RIGHT1) == 1)
		return (1);
	else if (tex_load(&sys->player_right[1], sys->mlx, PLAYER_RIGHT2) == 1)
		return (1);
	else if (tex_load(&sys->player_left[0], sys->mlx, PLAYER_LEFT1) == 1)
		return (1);
	else if (tex_load(&sys->player_left[1], sys->mlx, PLAYER_LEFT2) == 1)
		return (1);
	else if (tex_load(&sys->player_down[0], sys->mlx, PLAYER_DOWN1) == 1)
		return (1);
	else if (tex_load(&sys->player_down[1], sys->mlx, PLAYER_DOWN2) == 1)
		return (1);
}

static int	input_number(t_sys *sys)
{
	if (tex_load(&sys->num.num0, sys->mlx, NUMBER0) == 1)
		return (1);
	else if (tex_load(&sys->num.num1, sys->mlx, NUMBER1) == 1)
		return (1);
	else if (tex_load(&sys->num.num2, sys->mlx, NUMBER2) == 1)
		return (1);
	else if (tex_load(&sys->num.num3, sys->mlx, NUMBER3) == 1)
		return (1);
	else if (tex_load(&sys->num.num4, sys->mlx, NUMBER4) == 1)
		return (1);
	else if (tex_load(&sys->num.num5, sys->mlx, NUMBER5) == 1)
		return (1);
	else if (tex_load(&sys->num.num6, sys->mlx, NUMBER6) == 1)
		return (1);
	else if (tex_load(&sys->num.num7, sys->mlx, NUMBER7) == 1)
		return (1);
	else if (tex_load(&sys->num.num8, sys->mlx, NUMBER8) == 1)
		return (1);
	else if (tex_load(&sys->num.num9, sys->mlx, NUMBER9) == 1)
		return (1);
}

int	tex_input(t_sys *sys)
{
	sys->pl_dir = KEY_W;
	if (input_player(sys) == 1)
		return (1);
	else if (input_number(sys) == 1)
		return (1);
	else if (tex_load(&sys->collect[0], sys->mlx, COLLECT1) == 1)
		return (1);
	else if (tex_load(&sys->collect[1], sys->mlx, COLLECT2) == 1)
		return (1);
	else if (tex_load(&sys->wall, sys->mlx, WALL1) == 1)
		return (1);
	else if (tex_load(&sys->tile, sys->mlx, TILE1) == 1)
		return (1);
	else if (tex_load(&sys->goal, sys->mlx, GOAL1) == 1)
		return (1);
	return (0);
}
