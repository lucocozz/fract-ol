/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:29:22 by lucocozz          #+#    #+#             */
/*   Updated: 2021/06/15 01:57:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->screen.ptr);
	mlx_destroy_window(mlx->ptr, mlx->window.ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	gc_exit(EXIT_SUCCESS, NULL);
}

static t_mlx	init_mlx(char *name, t_axe size)
{
	t_mlx	mlx;
	char	*title;

	title = ft_strjoin("Fract-ol", name, ": ");
	mlx.ptr = mlx_init();
	mlx.window.size = size;
	mlx.window.ptr = mlx_new_window(mlx.ptr, size.x, size.y, title);
	mlx.screen.ptr = mlx_new_image(mlx.ptr, size.x, size.y);
	mlx.screen.data = (int *)mlx_get_data_addr(mlx.screen.ptr, &mlx.screen.bpp,
			&mlx.screen.line_size, &mlx.screen.endian);
	gc_free(title);
	return (mlx);
}

static void	*get_fractal(char *name)
{
	int						i;
	static t_fractal_info	fractals[] = {
		{"mandelbrot", &mandelbrot},
		{"julia", &julia},
		{NULL, NULL}
	};

	i = 0;
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
	return (fractals[i].function);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_fractal	fractal;

	if (argc < 2)
		gc_exit(EXIT_FAILURE, "Usage: ./fractol [fractal name]\n");
	fractal = (t_fractal){.name = argv[1], .function = get_fractal(argv[1])};
	mlx = init_mlx(fractal.name, (t_axe){.x = 800, .y = 800});
	events_hook(&mlx, &fractal);
	exit_mlx(&mlx);
	return (0);
}
