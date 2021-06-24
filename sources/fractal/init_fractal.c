/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:47:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/23 21:37:05 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal	*get_fractals(void)
{
	static t_fractal	fractals[] = {
		{.name = "mandelbrot", .function = &mandelbrot},
		{.name = "julia", .function = &julia},
		{.name = "burningship", .function = &burningship},
		{.name = NULL}
	};

	return (fractals);
}

t_fractal	init_fractal(char *name)
{
	int			i;
	t_fractal	*fractals;

	i = 0;
	fractals = get_fractals();
	while (fractals[i].name != NULL && ft_strcmp(fractals[i].name, name) != 0)
		i++;
	if (fractals[i].name == NULL)
	{
		i = 0;
		printf("Choose fractal between:\n");
		while (fractals[i].name != NULL)
			printf("  - %s\n", fractals[i++].name);
		exit(EXIT_FAILURE);
	}
	return (fractals[i]);
}
