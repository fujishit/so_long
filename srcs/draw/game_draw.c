#include "so_long.h"
#include "sl_config.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_tex(t_img *img, t_img *tex, int x, int y)
{
	int	i;
	int	n;
	float tex_x;
	float tex_y;
	int	color;

	i = 0;
	while (i < TEX_SIZE)
	{
		n = 0;
		while (n < TEX_SIZE)
		{
			// tex_x = (float)i / (float)TEX_SIZE;
			// tex_y = (float)n / (float)TEX_SIZE;
			// color = (get_pixel(tex, (int)(tex_x * tex->img_width), (int)(tex_y * tex->img_height)));
			// if (color != (int)0xFF000000)
				// my_mlx_pixel_put(img, x + i, y + n, color);
			// color = get_pixel(tex, i, n);
			color = 0xf5deb3;
			if ((int)color != 0xFF000000)
				my_mlx_pixel_put(img, x + i, y + n, color);
			n++;
		}
		i++;
	}
}

int	draw_tile(char **map, t_img *img, t_img *tile_tex)
{
	int	i;
	int	n;

	i = 0;
	// while (map[i] != NULL)
	// {
		n = 0;
	// 	while (map[i][n] != '\0')
	// 	{
			// if (map[i][n] == '1')
			draw_tex(img, tile_tex, i * TEX_SIZE, n * TEX_SIZE);
			// else
				// draw_tex(&sys->img, &sys->wall_tex, i * TEX_SIZE, n * TEX_SIZE);
	// 		n++;
	// 	}
	// 	i++;
	// }
}
