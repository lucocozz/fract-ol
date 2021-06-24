/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:29:22 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/23 16:56:26 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->screen.ptr);
	mlx_destroy_window(mlx->ptr, mlx->window);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	gc_exit(EXIT_SUCCESS, NULL);
}

static t_mlx	init_mlx(char *name)
{
	t_mlx	mlx;
	char	*title;

	title = ft_strjoin("Fract'ol: ", name, "");
	mlx.keys_hook = 0;
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, title);
	mlx.screen.ptr = mlx_new_image(mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.screen.data = (int *)mlx_get_data_addr(mlx.screen.ptr, &mlx.screen.bpp,
			&mlx.screen.line_size, &mlx.screen.endian);
	gc_free(title);
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_fractal	fractal;

	if (argc < 2)
		gc_exit(EXIT_FAILURE, "Usage: ./fractol [fractal name]\n");
	fractal = init_fractal(argv[1]);
	mlx = init_mlx(fractal.name);
	display_screen(&mlx, &fractal);
	events_hook(&mlx, &fractal);
	exit_mlx(&mlx);
	return (0);
}
