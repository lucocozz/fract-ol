/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:55:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/20 17:04:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_julia(t_fractal *fractal)
{
	fractal->iter_max = 150;
	fractal->palette = get_palette(0);
	fractal->min = (t_complex){.r = -1, .i = -1.2};
	fractal->max = (t_complex){.r = 1, .i = 1.2};
	fractal->zoom.r = WIN_WIDTH / (fractal->max.r - fractal->min.r);
	fractal->zoom.i = WIN_HEIGHT / (fractal->max.i - fractal->min.i);
	return (1);
}

static int	get_iteration(int x, int y, t_fractal *fractal)
{
	int			iter;
	double		tmp;
	t_complex	z;
	t_complex	c;

	iter = 0;
	c = (t_complex){.r = 0.285, .i = 0.01};
	z.r = x / fractal->zoom.r + fractal->min.r;
	z.i = y / fractal->zoom.i + fractal->min.i;
	while (pow(z.r, 2) + pow(z.i, 2) < 4 && iter < fractal->iter_max)
	{
		tmp = z.r;
		z.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		iter++;
	}
	return (iter);
}

void	julia(t_mlx *mlx, t_fractal *fractal)
{
	int			x;
	int			y;
	int			iter;
	static int	init = 0;

	x = 0;
	if (init == 0)
		init = init_julia(fractal);
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			iter = get_iteration(x, y, fractal);
			if (iter != fractal->iter_max)
				putpixel(mlx, x, y, iter * BLUE / fractal->iter_max);
			y++;
		}
		x++;
	}
}
