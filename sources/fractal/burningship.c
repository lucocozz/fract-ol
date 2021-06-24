/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:49:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/24 02:48:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_burningship(t_fractal *fractal)
{
	fractal->iter_max = 100;
	fractal->palette = get_palette(2);
	gradient(fractal, &interpolate_rgb);
	fractal->min = (t_complex){.r = -2, .i = -2};
	fractal->max = (t_complex){.r = 1, .i = 1};
	return (1);
}

static int	get_iteration(int x, int y, t_fractal *fractal)
{
	int			iter;
	double		tmp;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z = (t_complex){.r = 0, .i = 0};
	c.r = x / fractal->delta.r + fractal->min.r;
	c.i = y / fractal->delta.i + fractal->min.i;
	while (pow(z.r, 2) + pow(z.i, 2) < 4 && iter < fractal->iter_max)
	{
		tmp = z.r;
		z.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
		z.i = fabs(2 * tmp * z.i) + c.i;
		iter++;
	}
	return (iter);
}

void	burningship(t_mlx *mlx, t_fractal *fractal)
{
	int			x;
	int			y;
	int			iter;
	static int	init = 0;

	x = 0;
	if (init == 0)
		init = init_burningship(fractal);
	fractal->delta.r = WIN_WIDTH / (fractal->max.r - fractal->min.r);
	fractal->delta.i = WIN_HEIGHT / (fractal->max.i - fractal->min.i);
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			iter = get_iteration(x, y, fractal);
			if (iter != fractal->iter_max)
				putpixel(mlx, x, y, color(fractal, iter));
			y++;
		}
		x++;
	}
}
