#include "so_long.h"
#include "sl_config.h"

static t_img	*select_number(size_t num, t_num *nums)
{
	while (10 <= num)
	{
		num = num % 10;
	}
	if (num == 0)
		return (&nums->num0);
	else if (num == 1)
		return (&nums->num1);
	else if (num == 2)
		return (&nums->num2);
	else if (num == 3)
		return (&nums->num3);
	else if (num == 4)
		return (&nums->num4);
	else if (num == 5)
		return (&nums->num5);
	else if (num == 6)
		return (&nums->num6);
	else if (num == 7)
		return (&nums->num7);
	else if (num == 8)
		return (&nums->num8);
	else if (num == 9)
		return (&nums->num9);
	return (&nums->num0);
}

void	draw_count(t_sys *sys, t_num *num, size_t width, size_t count)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = 1;
	while (i < width && i < 10)
	{
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	while (0 < i)
	{
		draw_tex(&sys->img, select_number(count / temp, num), \
			sys->win_width - (i * TEX_SIZE), sys->win_height - 32);
		count = count % temp;
		temp = temp / 10;
		i--;
	}
}
