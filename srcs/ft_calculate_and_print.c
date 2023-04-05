/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_and_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:12:17 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/03 16:12:22 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_put_image_to_window(t_nest *nest)
{
	nest->img.img = mlx_new_image(nest->frac.mlx, nest->frac.window_width,
			nest->frac.window_height);
	if (!nest->img.img)
		ft_error(nest);
	nest->img.addr = mlx_get_data_addr(nest->img.img, &nest->img.bits_per_pixel,
			&nest->img.line_length, &nest->img.endian);
	if (!nest->img.addr)
		ft_error(nest);
	if (nest->frac.fractal_type == 1)
		ft_calculate_and_launch_mandelbrot(nest);
	else if (nest->frac.fractal_type == 2)
		ft_calculate_and_launch_julia(nest);
	else if (nest->frac.fractal_type == 3)
		ft_calculate_and_launch_ship(nest);
	mlx_put_image_to_window(nest->frac.mlx, nest->frac.mlx_win,
		nest->img.img, 0, 0);
	ft_text(nest);
}

void	my_mlx_pixel_put(t_nest *nest, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < nest->frac.window_width && y >= 0
		&& y < nest->frac.window_height)
	{
		dst = nest->img.addr + (y * nest->img.line_length + x
				* (nest->img.bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}
