#include "so_long.h"

static void	wrap_destroy_image(void *mlx, t_img *img)
{
	if (img->image != NULL)
		mlx_destroy_image(mlx, img->image);
}

void		destroy_texture(t_sys *sys)
{
	wrap_destroy_image(sys->mlx, &sys->img);
	wrap_destroy_image(sys->mlx, &sys->num.num0);
	wrap_destroy_image(sys->mlx, &sys->num.num1);
	wrap_destroy_image(sys->mlx, &sys->num.num2);
	wrap_destroy_image(sys->mlx, &sys->num.num3);
	wrap_destroy_image(sys->mlx, &sys->num.num4);
	wrap_destroy_image(sys->mlx, &sys->num.num5);
	wrap_destroy_image(sys->mlx, &sys->num.num6);
	wrap_destroy_image(sys->mlx, &sys->num.num7);
	wrap_destroy_image(sys->mlx, &sys->num.num8);
	wrap_destroy_image(sys->mlx, &sys->num.num9);
	wrap_destroy_image(sys->mlx, &sys->player_up[0]);
	wrap_destroy_image(sys->mlx, &sys->player_up[1]);
	wrap_destroy_image(sys->mlx, &sys->player_right[0]);
	wrap_destroy_image(sys->mlx, &sys->player_right[1]);
	wrap_destroy_image(sys->mlx, &sys->player_left[0]);
	wrap_destroy_image(sys->mlx, &sys->player_left[1]);
	wrap_destroy_image(sys->mlx, &sys->player_down[0]);
	wrap_destroy_image(sys->mlx, &sys->player_down[1]);
	wrap_destroy_image(sys->mlx, &sys->collect[0]);
	wrap_destroy_image(sys->mlx, &sys->collect[1]);
	wrap_destroy_image(sys->mlx, &sys->wall);
	wrap_destroy_image(sys->mlx, &sys->tile);
	wrap_destroy_image(sys->mlx, &sys->goal);
	wrap_destroy_image(sys->mlx, &sys->enemy);
}
