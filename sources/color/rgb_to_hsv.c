/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hsv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:23:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/23 02:19:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	min(t_frgb rgb)
{
	float	min;

	min = rgb.red;
	if (rgb.red < rgb.green)
		min = rgb.red;
	else
		min = rgb.green;
	if (min > rgb.blue)
		min = rgb.blue;
	return (min);
}

static float	max(t_frgb rgb)
{
	float	max;

	max = rgb.red;
	if (rgb.red > rgb.green)
		max = rgb.red;
	else
		max = rgb.green;
	if (max < rgb.blue)
		max = rgb.blue;
	return (max);
}

static int	calculate_hue(t_frgb rgb, float cmin, float cmax)
{
	float	hue;

	hue = 0.0;
	if (cmax == cmin)
		hue = 0;
	else if (rgb.red == cmax)
		hue = (rgb.green - rgb.blue) / (cmax - cmin);
	else if (rgb.green == cmax)
		hue = 2.0 + (rgb.blue - rgb.red) / (cmax - cmin);
	else if (rgb.blue == cmax)
		hue = 4.0 + (rgb.red - rgb.green) / (cmax - cmin);
	hue *= 60;
	if (hue < 0)
		hue += 360;
	return (hue);
}

t_hsv	rgb_to_hsv(t_rgb color)
{
	float	cmin;
	float	cmax;
	t_frgb	rgb;
	t_hsv	hsv;

	rgb = (t_frgb){color.red / 255.0, color.green / 255.0, color.blue / 255.0};
	cmin = min(rgb);
	cmax = max(rgb);
	hsv.hue = calculate_hue(rgb, cmin, cmax);
	if (cmax == 0)
		hsv.saturation = 0;
	else
		hsv.saturation = ((cmax - cmin) / cmax);
	hsv.value = cmax;
	return (hsv);
}
