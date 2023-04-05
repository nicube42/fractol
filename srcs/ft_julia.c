/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:13:16 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/03 16:13:20 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_init_julia(t_fractol *frac)
{
	frac->iter = 0;
	frac->z_real = frac->x / frac->zoom_x + frac->x_min;
	frac->z_im = frac->y / frac->zoom_y + frac->y_min;
}

void	ft_calculate_and_launch_julia(t_nest *nest)
{
	nest->frac.x = -1;
	while (nest->frac.x < nest->frac.img_x)
	{
		nest->frac.y = 0;
		while (nest->frac.y < nest->frac.img_y)
		{
			ft_init_julia(&nest->frac);
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

void	ft_julia_set(t_fractol *frac)
{
	frac->iter = 0;
	frac->x_min = -2.0;
	frac->x_max = 2.0;
	frac->y_min = -2.0;
	frac->y_max = 2.0;
	frac->zoom_x = 300;
	frac->zoom_y = 300;
	frac->display_shift = 0.1;
	frac->z_real = 0;
	frac->z_im = 0;
	frac->max_iter = 100;
	frac->img_x = frac->window_width;
	frac->img_y = frac->window_height;
	frac->color = 0x00660000;
	frac->fractal_type = 2;
	frac->i_color = 1;
	frac->name = "Fractol : Julia";
}
