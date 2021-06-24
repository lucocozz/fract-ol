/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:49:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/24 02:49:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mandelbrot(t_fractal *fractal)
{
	fractal->iter_max = 50;
	fractal->palette = get_palette(0);
	gradient(fractal, &interpolate_hsv);
	fractal->min = (t_complex){.r = -2.1, .i = -1.2};
	fractal->max = (t_complex){.r = 0.6, .i = 1.2};
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
	c.r = fractal->min.r + x * fractal->delta.r;
	c.i = fractal->min.i + y * fractal->delta.i;
	while (pow(z.r, 2) + pow(z.i, 2) < 4 && iter < fractal->iter_max)
	{
		tmp = z.r;
		z.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		iter++;
	}
	return (iter);
}

void	mandelbrot(t_mlx *mlx, t_fractal *fractal)
{
	int			x;
	int			y;
	int			iter;
	static int	init = 0;

	x = 0;
	if (init == 0)
		init = init_mandelbrot(fractal);
	fractal->delta.r = (fractal->max.r - fractal->min.r) / (WIN_WIDTH - 1);
	fractal->delta.i = (fractal->max.i - fractal->min.i) / (WIN_HEIGHT - 1);
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
