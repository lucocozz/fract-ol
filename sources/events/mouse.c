/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:14:31 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/25 13:49:17 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_events(int key, int x, int y, t_params *params)
{
	t_mlx			*mlx;
	t_fractal		*fractal;

	(void)(x & y);
	mlx = params->mlx;
	fractal = params->fractal;
	if (key == 4)
		zoom_in(mlx, fractal);
	else if (key == 5)
		zoom_out(mlx, fractal);
	draw_fractal(mlx, fractal);
	display_screen(mlx);
	return (0);
}
