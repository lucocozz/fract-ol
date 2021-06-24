/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:44:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/24 02:58:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpolate_rgb(t_fractal *fractal, int index, float ratio)
{
	t_rgb	color1;
	t_rgb	color2;
	t_rgb	result;

	color1 = hexa_to_rgb(fractal->palette.colors[index]);
	color2 = hexa_to_rgb(fractal->palette.colors[(index + 1)
			% fractal->palette.size]);
	result.red = color1.red + ratio * (color2.red - color1.red);
	result.green = color1.green + ratio * (color2.green - color1.green);
	result.blue = color1.blue + ratio * (color2.blue - color1.blue);
	return (rgb_to_hexa(result));
}

int	interpolate_hsv(t_fractal *fractal, int index, float ratio)
{
	t_hsv	color1;
	t_hsv	color2;
	t_hsv	result;

	color1 = rgb_to_hsv(hexa_to_rgb(fractal->palette.colors[index]));
	color2 = rgb_to_hsv(hexa_to_rgb(fractal->palette.colors[(index + 1)
				% fractal->palette.size]));
	result.hue = color1.hue + ratio * (color2.hue - color1.hue);
	result.saturation = color1.saturation + ratio
		* (color2.saturation - color1.saturation);
	result.value = color1.value + ratio * (color2.value - color1.value);
	return (rgb_to_hexa(hsv_to_rgb(result)));
}

void	gradient(t_fractal *fractal,
	int (*interpolate)(t_fractal *, int, float))
{
	int		i;
	int		j;
	int		color;
	int		range;

	j = 0;
	fractal->palette.gradient = gc_malloc(sizeof(int) * fractal->palette.shade);
	range = fractal->palette.shade / fractal->palette.size;
	while (j < fractal->palette.size)
	{
		i = 0;
		while (i < range)
		{
			color = interpolate(fractal, j, (float)i / (float)range);
			fractal->palette.gradient[i + (int)(range * j)] = color;
			i++;
		}
		j++;
	}
}
