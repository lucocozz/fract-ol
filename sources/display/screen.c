/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:19:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/24 18:11:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel(t_mlx *mlx, int x, int y, int color)
{
	mlx->screen.data[y * WIN_WIDTH + x] = color;
}

void	draw_fractal(t_mlx *mlx, t_fractal *fractal)
{
	ft_bzero(mlx->screen.data, WIN_HEIGHT * mlx->screen.line_size);
	fractal->function(mlx, fractal);
}

void	display_screen(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->screen.ptr, 0, 0);
}
