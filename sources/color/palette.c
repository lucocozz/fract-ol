/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:04:24 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/24 03:23:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	get_palette(int index)
{
	static t_palette	palettes[] = {
		{
			.size = 3,
			.shade = 60,
			.colors = {MIDDLE_YELLOW, SHOCKING_PINK, INTERDIMENSIONAL_BLUE}
		},
		{
			.size = 2,
			.shade = 40,
			.colors = {INTERDIMENSIONAL_BLUE, ORANGE}
		},
		{
			.size = 3,
			.shade = 60,
			.colors = {ORANGE_BROWN, FLAME, MIDDLE_YELLOW}
		}
	};

	return (palettes[index]);
}
