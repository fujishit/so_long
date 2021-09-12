#include "so_long.h"

int	get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->size_l + (x * (img->bpp / 8)))));
}

void	get_color(t_img *img, int x, int y, int c)
{
	*(unsigned int *)(img->addr + (y * img->size_l + x * (img->bpp / 8))) = c;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
