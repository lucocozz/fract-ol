/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:25:23 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/25 13:55:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_key_event	*get_events(void)
{
	static t_key_event	events[] = {
		{.key = ESC_KEY, .event = &esc_key},
		{.key = KEY_UP, .event = &zoom_in},
		{.key = KEY_DOWN, .event = &zoom_out},
		{0, NULL}
	};

	return (events);
}

static int	press_event(int key, t_params *params)
{
	int			i;
	t_mlx		*mlx;
	t_key_event	*events;

	i = 0;
	mlx = params->mlx;
	events = get_events();
	while (events[i].key != 0 && events[i].key != key)
		i++;
	if (events[i].key != 0)
		mlx->keys_hook |= 1 << i;
	return (0);
}

static int	release_event(int key, t_params *params)
{
	int			i;
	t_mlx		*mlx;
	t_key_event	*events;

	i = 0;
	mlx = params->mlx;
	events = get_events();
	while (events[i].key != 0 && events[i].key != key)
		i++;
	if (events[i].key != 0)
		mlx->keys_hook &= ~(1 << i);
	return (0);
}

static int	loop_event(t_params *params)
{
	int				i;
	t_mlx			*mlx;
	t_fractal		*fractal;
	t_key_event		*events;

	i = 0;
	mlx = params->mlx;
	fractal = params->fractal;
	events = get_events();
	if (mlx->keys_hook)
	{
		while (events[i].key != 0)
		{
			if ((mlx->keys_hook >> i) & 1)
				events[i].event(mlx, fractal);
			i++;
		}
		draw_fractal(mlx, fractal);
	}
	display_screen(mlx);
	return (0);
}

void	events_hook(t_mlx *mlx, t_fractal *fractal)
{
	t_params	params;

	params = (t_params){.mlx = mlx, .fractal = fractal};
	mlx_hook(mlx->window, CLOSE, 0, &mlx_loop_end, mlx->ptr);
	mlx_hook(mlx->window, KEY_PRESS, 1, &press_event, &params);
	mlx_hook(mlx->window, KEY_RELEASE, 2, &release_event, &params);
	mlx_mouse_hook(mlx->window, &mouse_events, &params);
	mlx_loop_hook(mlx->ptr, &loop_event, &params);
	mlx_loop(mlx->ptr);
}
