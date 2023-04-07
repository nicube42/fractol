/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:22:03 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/05 11:31:40 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../libft_printf/includes/libft.h"
# include "../libft_printf/includes/ft_printf.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
	int		color;
	int		x;
	double	x_min;
	double	x_max;
	int		y;
	double	y_min;
	double	y_max;
	double	zoom_x;
	double	zoom_y;
	float	display_shift;
	int		img_x;
	int		img_y;
	double	z_real;
	double	z_im;
	double	c_real;
	double	c_im;
	double	tmp;
	double	iter;
	int		max_iter;
	int		fractal_type;
	int		i_color;
	char	*name;
}				t_fractol;

typedef struct s_nest
{
	t_img		img;
	t_fractol	frac;
}				t_nest;

/*int ft_strncmp(const char *s1, const char *s2, size_t n);
double ft_atof(const char *str);
int ft_isdigit(int c);*/

int		main(int argc, char **argv);
void	ft_select_fractal(t_nest *nest, int argc, char **argv);
void	ft_init_mlx(t_nest *nest);

int		ft_zoom_hook(int keycode, int x, int y, t_nest *nest);
int		ft_key_hook(int keycode, t_nest *nest);
int		ft_key_hook_2(int keycode, t_nest *nest);

void	ft_put_image_to_window(t_nest *nest);
void	my_mlx_pixel_put(t_nest *nest, int x, int y, int color);

void	ft_init_mandelbrot(t_fractol *frac);
void	ft_calculate_and_launch_mandelbrot(t_nest *nest);
void	ft_mandelbrot_set(t_fractol *frac);

void	ft_init_julia(t_fractol *frac);
void	ft_calculate_and_launch_julia(t_nest *nest);
void	ft_julia_set(t_fractol *frac);

void	ft_init_ship(t_fractol *frac);
void	ft_calculate_and_launch_ship(t_nest *nest);
void	ft_ship_set(t_fractol *frac);

void	ft_clean_exit(t_nest *nest);
void	ft_error(t_nest *nest);
int		ft_ok(t_nest *nest);
void	ft_julia_text(t_nest *nest);
void	ft_general_text(t_nest *nest);

void	ft_text(t_nest *nest);

#endif
