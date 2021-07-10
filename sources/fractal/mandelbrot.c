/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:49:21 by lucocozz          #+#    #+#             */
/*   Updated: 2021/07/09 18:45:56 by lucocozz         ###   ########.fr       */
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
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	iter = 0;
	z = (t_complex){.r = 0, .i = 0};
	c.r = fractal->min.r + x * fractal->delta.r;
	c.i = fractal->min.i + y * fractal->delta.i;
	tmp = (t_complex){.r = 0, .i = 0};
	while (tmp.r + tmp.i < 4 && iter < fractal->iter_max)
	{
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += c.i;
		z.r = tmp.r - tmp.i + c.r;
		tmp.r = z.r * z.r;
		tmp.i = z.i * z.i;
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
