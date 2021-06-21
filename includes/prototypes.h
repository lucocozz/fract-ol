/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:10:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/20 23:16:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//	main
void		exit_mlx(t_mlx *mlx);

//	fractal
void		julia(t_mlx *mlx, t_fractal *fractal);
void		mandelbrot(t_mlx *mlx, t_fractal *fractal);

//	init_fractal
t_fractal	init_fractal(char *name);

//	events
//		hooks
void		events_hook(t_mlx *mlx, t_fractal *fractal);
//		keys
void		esc_key(t_mlx *mlx, t_fractal *fractal);
//		mouse
int			mouse_events(int key, int x, int y, t_params *params);
void		scroll_down(t_mlx *mlx, t_fractal *fractal);
void		scroll_up(t_mlx *mlx, t_fractal *fractal);

//	screen
void		display_screen(t_mlx *mlx, t_fractal *fractal);
void		putpixel(t_mlx *mlx, int x, int y, int color);

//	color
t_palette	get_palette(int index);
int			rgb(t_rgb color);
t_rgb		hexa_to_rgb(int hexa);
int			color(t_fractal *fractal, int iter);
void		init_gradient(t_fractal *fractal);

#endif
