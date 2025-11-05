/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:52:35 by sreffers          #+#    #+#             */
/*   Updated: 2025/11/05 14:19:16 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_KP_Add)
	{
		if (fractal->iteration_definition + 10 < MAX_ITER)
			fractal->iteration_definition += 10;
	}
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		if (fractal->iteration_definition - 10 > 0)
			fractal->iteration_definition -= 10;
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	zoom_factor = 0.0;
	mouse_x = map(x, -2, 2, WIDTH - 1) * fractal->zoom + fractal->shift_x;
	mouse_y = map(y, 2, -2, HEIGHT - 1) * fractal->zoom + fractal->shift_y;
	if (button == Button5)
		zoom_factor = 1.05;
	else if (button == Button4)
		zoom_factor = 0.95;
	else
		return (0);
	fractal->zoom *= zoom_factor;
	fractal->shift_x = mouse_x - map(x, -2, 2, WIDTH - 1) * fractal->zoom;
	fractal->shift_y = mouse_y - map(y, 2, -2, HEIGHT - 1) * fractal->zoom;
	fractal_render(fractal);
	return (0);
}
