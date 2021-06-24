/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:24:06 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/23 03:00:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	float	x;
	float	min;
	float	chroma;
	t_frgb	rgb;

	chroma = hsv.value * hsv.saturation;
	x = chroma * (1.0 - fabs(fmod(hsv.hue / 60.0, 2) - 1.0));
	min = hsv.value - chroma;
	if (hsv.hue >= 0.0 && hsv.hue < 60.0)
		rgb = (t_frgb){chroma + min, x + min, min};
	else if (hsv.hue >= 60.0 && hsv.hue < 120.0)
		rgb = (t_frgb){x + min, chroma + min, min};
	else if (hsv.hue >= 120.0 && hsv.hue < 180.0)
		rgb = (t_frgb){min, chroma + min, x + min};
	else if (hsv.hue >= 180.0 && hsv.hue < 240.0)
		rgb = (t_frgb){min, x + min, chroma + min};
	else if (hsv.hue >= 240.0 && hsv.hue < 300.0)
		rgb = (t_frgb){x + min, min, chroma + min};
	else if (hsv.hue >= 300.0 && hsv.hue < 360.0)
		rgb = (t_frgb){chroma + min, min, x + min};
	else
		rgb = (t_frgb){min, min, min};
	return ((t_rgb){rgb.red * 255, rgb.green * 255, rgb.blue * 255});
}
