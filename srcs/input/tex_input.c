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
	tex->addr = (int *)mlx_get_data_addr(\
		tex->img, &tex->bpp, &tex->size_l, &tex->endian);
	if (tex->addr == NULL)
	{
		error_print(MLX_ERROR);
		return (1);
	}
	return (0);
}

int	tex_input(t_sys *sys)
{
	if (tex_load(&sys->player_tex, sys->mlx, PLAYER) == 1)
		return (1);
	if (tex_load(&sys->wall_tex, sys->mlx, WALL) == 1)
		return (1);
	if (tex_load(&sys->tile_tex, sys->mlx, TILE) == 1)
		return (1);
	return (0);
}
