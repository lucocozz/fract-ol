/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:44:37 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/15 01:35:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_fractal_info
{
	char		*name;
	void		(*function)();
}				t_fractal_info;

typedef struct s_axe
{
	int			x;
	int			y;
}				t_axe;

typedef struct s_axe_foat
{
	float		x;
	float		y;
}				t_axe_foat;

typedef struct s_fractal
{
	char		*name;
	void		(*function)();
}				t_fractal;

typedef struct s_image
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_window
{
	void		*ptr;
	t_axe		size;
}				t_window;

typedef struct s_mlx
{
	void		*ptr;
	t_image		screen;
	t_window	window;
}				t_mlx;

typedef struct s_params
{
	t_mlx		*mlx;
	t_fractal	*fractal;
}				t_params;

#endif
