/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:54:10 by sreffers          #+#    #+#             */
/*   Updated: 2025/11/05 00:05:07 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or\
\n\t\"./fractol julia <value_1>> <value_2>\" or\n\
\t\"./fractol tricorn\"\n"
# define ERROR_MESSAGE_VALUE "Please enter correct values between -2 and 2\n"
# define WIDTH 950
# define HEIGHT 950
# define MAX_ITER 500

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iteration_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}	t_fractal;

void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		atodbl(char *str);
int			is_double(char *s);
int			is_valid(char **av, int size);
void		handle_pixel(int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(
				int button,
				int x,
				int y,
				t_fractal *fractal);
double		map(
				double unscaled_num,
				double new_min,
				double new_max,
				double old_max);
int			key_handler(int keysym, t_fractal *fractal);
#endif
