/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:56:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/24 02:46:37 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_mlx *mlx, t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	offset;

	mlx_mouse_get_pos(mlx->ptr, mlx->window, &x, &y);
	offset.r = (double)x / (WIN_WIDTH / (fractal->max.r - fractal->min.r))
		+ fractal->min.r;
	offset.i = (double)y / (WIN_HEIGHT / (fractal->max.i - fractal->min.i))
		+ fractal->min.i;
	fractal->min.r = offset.r + ((fractal->min.r - offset.r) * (1.0 / 1.2));
	fractal->min.i = offset.i + ((fractal->min.i - offset.i) * (1.0 / 1.2));
	fractal->max.r = offset.r + ((fractal->max.r - offset.r) * (1.0 / 1.2));
	fractal->max.i = offset.i + ((fractal->max.i - offset.i) * (1.0 / 1.2));
	fractal->iter_max += 4;
}

void	zoom_out(t_mlx *mlx, t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	offset;

	mlx_mouse_get_pos(mlx->ptr, mlx->window, &x, &y);
	offset.r = (double)x / (WIN_WIDTH / (fractal->max.r - fractal->min.r))
		+ fractal->min.r;
	offset.i = (double)y / (WIN_HEIGHT / (fractal->max.i - fractal->min.i))
		+ fractal->min.i;
	fractal->min.r = offset.r + ((fractal->min.r - offset.r) * (1.0 / 0.8));
	fractal->min.i = offset.i + ((fractal->min.i - offset.i) * (1.0 / 0.8));
	fractal->max.r = offset.r + ((fractal->max.r - offset.r) * (1.0 / 0.8));
	fractal->max.i = offset.i + ((fractal->max.i - offset.i) * (1.0 / 0.8));
	fractal->iter_max -= 4;
}
