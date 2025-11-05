/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:01:27 by sreffers          #+#    #+#             */
/*   Updated: 2025/11/05 14:37:31 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	is_julia(char **av, int ac, t_fractal *fractal)
{
	if (!is_valid(av, ac))
	{
		ft_putstr_fd(ERROR_MESSAGE_VALUE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
	{
		fractal->julia_x = atodbl(av[2]);
		fractal->julia_y = atodbl(av[3]);
	}
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
		|| (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
		|| (ac == 2 && ft_strncmp(av[1], "tricorn", 7) == 0))
	{
		fractal.name = av[1];
		if (ft_strncmp(av[1], "julia", 6) == 0)
			is_julia(av, ac, &fractal);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
