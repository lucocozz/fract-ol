/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:56:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/25 14:11:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_mlx *mlx, t_fractal *fractal, double percent)
{
	int			x;
	int			y;
	t_complex	offset;

	mlx_mouse_get_pos(mlx->ptr, mlx->window, &x, &y);
	offset.r = (double)x / (WIN_WIDTH / (fractal->max.r - fractal->min.r))
		+ fractal->min.r;
	offset.i = (double)y / (WIN_HEIGHT / (fractal->max.i - fractal->min.i))
		+ fractal->min.i;
	fractal->min.r = offset.r + ((fractal->min.r - offset.r) * percent);
	fractal->min.i = offset.i + ((fractal->min.i - offset.i) * percent);
	fractal->max.r = offset.r + ((fractal->max.r - offset.r) * percent);
	fractal->max.i = offset.i + ((fractal->max.i - offset.i) * percent);
}

void	zoom_in(t_mlx *mlx, t_fractal *fractal)
{
	zoom(mlx, fractal, 1.0 / 1.2);
	fractal->iter_max += 4;
}

void	zoom_out(t_mlx *mlx, t_fractal *fractal)
{
	zoom(mlx, fractal, 1.0 / 0.8);
	fractal->iter_max -= 4;
}
