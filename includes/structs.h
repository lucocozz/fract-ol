/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:44:37 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/20 23:01:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_fractal_info
{
	char			*name;
	void			(*function)();
}					t_fractal_info;

typedef struct s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct s_palette
{
	int				size;
	int				colors[MAX_COLOR];
	int				gradient[MAX_COLOR];
}					t_palette;

typedef struct s_fractal
{
	char			*name;
	void			(*function)();
	int				iter_max;
	t_palette		palette;
	t_complex		zoom;
	t_complex		min;
	t_complex		max;
}					t_fractal;

typedef struct s_image
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				line_size;
	int				endian;
}					t_image;

typedef struct s_mlx
{
	void			*ptr;
	void			*window;
	int				keys_hook;
	t_image			screen;
}					t_mlx;

typedef struct s_params
{
	t_mlx			*mlx;
	t_fractal		*fractal;
}					t_params;

typedef struct s_key_event
{
	int				key;
	void			(*event)();
}					t_key_event;

typedef struct s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_rgb;

#endif
