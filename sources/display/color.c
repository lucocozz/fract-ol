/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:44:01 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/21 15:59:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	get_palette(int index)
{
	static t_palette	palettes[] = {
		{.size = 3, .colors = {MIDDLE_YELLOW, SHOCKING_PINK, TURQUOISE_BLUE}}
	};

	return (palettes[index]);
}

int	rgb(t_rgb color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}

t_rgb	hexa_to_rgb(int hexa)
{
	t_rgb	rgb;

	rgb.red = hexa & RED >> 16;
	rgb.green = hexa & GREEN >> 8;
	rgb.blue = hexa & BLUE;
	return (rgb);
}

static int	mix_color(t_fractal *fractal, int index, float ratio)
{
	t_rgb	color1;
	t_rgb	color2;
	t_rgb	result;

	color1 = hexa_to_rgb(fractal->palette.colors[index]);
	color2 = hexa_to_rgb(fractal->palette.colors[(index + 1) % fractal->palette.size]);
	result.red = color1.red + ratio * (color2.red - color1.red);
	result.green = color1.green + ratio * (color2.green - color1.green);
	result.blue = color1.blue + ratio * (color2.blue - color1.blue);
	return (rgb(result));
}

void	init_gradient(t_fractal *fractal)
{
	int		i;
	int		j;
	int		color;
	float	ratio;
	int		range;

	j = 0;
	range = MAX_COLOR / fractal->palette.size;
	while (j < fractal->palette.size)
	{
		i = 0;
		while (i < range)
		{
			ratio = i / range;
			color = mix_color(fractal, j, ratio);
			fractal->palette.gradient[i + (int)(range * j)] = color;
			i++;
		}
		j++;
	}
}

int	color(t_fractal *fractal, int iter)
{
	return (fractal->palette.gradient[iter % MAX_COLOR]);
}
