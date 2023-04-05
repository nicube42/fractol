/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:13:48 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/03 16:13:53 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_init_mandelbrot(t_fractol *frac)
{
	frac->iter = 0;
	frac->c_real = frac->x / frac->zoom_x + frac->x_min;
	frac->c_im = frac->y / frac->zoom_y + frac->y_min;
	frac->z_real = 0;
	frac->z_im = 0;
}

void	ft_calculate_and_launch_mandelbrot(t_nest *nest)
{
	nest->frac.x = -1;
	while (nest->frac.x < nest->frac.img_x)
	{
		nest->frac.y = 0;
		while (nest->frac.y < nest->frac.img_y)
		{
			ft_init_mandelbrot(&nest->frac);
			while (nest->frac.z_real * nest->frac.z_real + nest->frac.z_im
				* nest->frac.z_im < 4 && nest->frac.iter < nest->frac.max_iter)
			{
				nest->frac.tmp = nest->frac.z_real;
				nest->frac.z_real = nest->frac.z_real * nest->frac.z_real
					- nest->frac.z_im * nest->frac.z_im + nest->frac.c_real;
				nest->frac.z_im = 2 * nest->frac.z_im * nest->frac.tmp
					+ nest->frac.c_im;
				nest->frac.iter++;
			}
			my_mlx_pixel_put(nest, nest->frac.x, nest->frac.y, nest->frac.iter
				* nest->frac.color / nest->frac.max_iter);
			nest->frac.y++;
		}
		nest->frac.x++;
	}
}	

void	ft_mandelbrot_set(t_fractol *frac)
{
	frac->iter = 0;
	frac->x_min = -2.0;
	frac->x_max = 2.0;
	frac->y_min = -2.0;
	frac->y_max = 2.0;
	frac->zoom_x = 300;
	frac->zoom_y = 300;
	frac->display_shift = 0.1;
	frac->c_real = frac->x / frac->zoom_x + frac->x_min;
	frac->c_im = frac->y / frac->zoom_y + frac->y_min;
	frac->z_real = 0;
	frac->z_im = 0;
	frac->max_iter = 100;
	frac->img_x = frac->window_width;
	frac->img_y = frac->window_height;
	frac->color = 0x00660000;
	frac->fractal_type = 1;
	frac->i_color = 1;
	frac->name = "Fractol : Mandelbrot";
}
