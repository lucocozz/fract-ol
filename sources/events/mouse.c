/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:14:31 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/20 20:21:46 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_down(t_mlx *mlx, t_fractal *fractal)
{
	(void)mlx;
	fractal->zoom.r /= 1.1;
	fractal->zoom.i /= 1.1;
	fractal->max.r *= 0.15;
	fractal->max.i *= 0.15;
	fractal->min.r /= 0.15;
	fractal->min.i /= 0.15;
	fractal->iter_max -= 10;
}

void	scroll_up(t_mlx *mlx, t_fractal *fractal)
{
	(void)mlx;
	fractal->zoom.r *= 0.6;
	fractal->zoom.i *= 0.6;
	fractal->max.r /= 0.15;
	fractal->max.i /= 0.15;
	fractal->min.r *= 0.15;
	fractal->min.i *= 0.15;
	fractal->iter_max += 10;
}

int	mouse_events(int key, int x, int y, t_params *params)
{
	t_mlx			*mlx;
	t_fractal		*fractal;

	(void)(x & y);
	mlx = params->mlx;
	fractal = params->fractal;
	if (key == 4)
		scroll_up(mlx, fractal);
	else if (key == 5)
		scroll_down(mlx, fractal);
	display_screen(mlx, fractal);
	return (0);
}
