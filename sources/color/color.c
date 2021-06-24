/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:10:35 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/23 16:55:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb_to_hexa(t_rgb color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}

t_rgb	hexa_to_rgb(int hexa)
{
	t_rgb	rgb;

	rgb.red = (hexa & RED) >> 16;
	rgb.green = (hexa & GREEN) >> 8;
	rgb.blue = (hexa & BLUE);
	return (rgb);
}

int	color(t_fractal *fractal, int iter)
{
	return (fractal->palette.gradient[iter % fractal->palette.shade]);
}
