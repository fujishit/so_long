#include "so_long.h"
#include "sl_config.h"

static int	get_color(t_img *img, int x, int y)
{
	return (*(int *)(img->data + (y * img->size_line + (x * (img->bpp / 8)))));
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_tex(t_img *img, t_img *tex, int x, int y)
{
	int	i;
	int	n;
	int	color;

	i = 0;
	while (i < TEX_SIZE)
	{
		n = 0;
		while (n < TEX_SIZE)
		{
			color = (get_color(tex, i, n));
			if (color != (int)0xFF000000)
				my_mlx_pixel_put(img, x + i, y + n, color);
			n++;
		}
		i++;
	}
}
