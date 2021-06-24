/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:10:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/23 21:39:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//	main
void		exit_mlx(t_mlx *mlx);

//	fractal
void		julia(t_mlx *mlx, t_fractal *fractal);
void		mandelbrot(t_mlx *mlx, t_fractal *fractal);
void		burningship(t_mlx *mlx, t_fractal *fractal);

//	init_fractal
t_fractal	init_fractal(char *name);

//	events
//		hooks
void		events_hook(t_mlx *mlx, t_fractal *fractal);
//		keys
void		esc_key(t_mlx *mlx, t_fractal *fractal);
//		mouse
int			mouse_events(int key, int x, int y, t_params *params);
void		zoom_in(t_mlx *mlx, t_fractal *fractal);
void		zoom_out(t_mlx *mlx, t_fractal *fractal);

//	display
//		screen
void		display_screen(t_mlx *mlx, t_fractal *fractal);
void		putpixel(t_mlx *mlx, int x, int y, int color);

//	color
//		palette
t_palette	get_palette(int index);
//		gradient
void		gradient(t_fractal *fractal,
				int (*interpolate)(t_fractal *, int, float));
int			interpolate_rgb(t_fractal *fractal, int index, float ratio);
int			interpolate_hsv(t_fractal *fractal, int index, float ratio);
//		color
int			color(t_fractal *fractal, int iter);
int			rgb_to_hexa(t_rgb color);
t_rgb		hexa_to_rgb(int hexa);
//		hsv_to_rgb
t_rgb		hsv_to_rgb(t_hsv hsv);
//		rgb_to_hsv
t_hsv		rgb_to_hsv(t_rgb color);

#endif
