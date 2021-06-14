/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:25:23 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/15 01:45:05 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	press_event(int key, t_params *params)
{
	(void)(key && params);
	return (0);
}

static int	release_event(int key, t_params *params)
{
	(void)(key && params);
	return (0);
}

static int	loop_event(t_params *params)
{
	(void)params;
	return (0);
}

void	events_hook(t_mlx *mlx, t_fractal *fractal)
{
	t_params	params;

	params = (t_params){.mlx = mlx, .fractal = fractal};
	mlx_hook(mlx->window.ptr, DESTROY_NOTIFY, 0, &mlx_loop_end, mlx->ptr);
	mlx_hook(mlx->window.ptr, KEY_PRESS, 1, &press_event, (void *)&params);
	mlx_hook(mlx->window.ptr, KEY_RELEASE, 2, &release_event, (void *)&params);
	mlx_loop_hook(mlx->ptr, &loop_event, (void *)&params);
	mlx_loop(mlx->ptr);
}
