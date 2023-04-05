/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:13:04 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/03 16:13:08 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include <unistd.h>

int	ft_key_hook(int keycode, t_nest *nest)
{
	if (keycode == 8)
	{
		if (nest->frac.i_color == 0)
			nest->frac.color = 0x00660000;
		if (nest->frac.i_color == 1)
			nest->frac.color = 0x0099FFFF;
		if (nest->frac.i_color == 2)
			nest->frac.color = 0x009999FF;
		nest->frac.i_color++;
		if (nest->frac.i_color == 3)
		{
			nest->frac.color = 0x00FF9966;
			nest->frac.i_color = 0;
		}
	}
	else if (keycode == 53)
	{
		mlx_destroy_image(nest->frac.mlx, nest->img.img);
		mlx_destroy_window(nest->frac.mlx, nest->frac.mlx_win);
		exit(0);
	}
	ft_key_hook_2(keycode, nest);
	ft_put_image_to_window(nest);
	return (0);
}

int	ft_key_hook_2(int keycode, t_nest *nest)
{
	if (keycode == 12)
		nest->frac.max_iter -= 10;
	else if (keycode == 13)
		nest->frac.max_iter += 10;
	else if (keycode == 126)
		nest->frac.y_min = nest->frac.y_min - nest->frac.display_shift;
	else if (keycode == 125)
		nest->frac.y_min = nest->frac.y_min + nest->frac.display_shift;
	else if (keycode == 123)
		nest->frac.x_min = nest->frac.x_min - nest->frac.display_shift;
	else if (keycode == 124)
		nest->frac.x_min = nest->frac.x_min + nest->frac.display_shift;
	return (0);
}

int	ft_zoom_hook(int keycode, int x, int y, t_nest *nest)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = x / nest->frac.zoom_x + nest->frac.x_min;
	tmp_y = y / nest->frac.zoom_y + nest->frac.y_min;
	if (keycode == 5)
	{
		nest->frac.zoom_x *= 1.1;
		nest->frac.zoom_y *= 1.1;
		nest->frac.display_shift /= 1.1;
	}
	if (keycode == 4)
	{
		nest->frac.zoom_x /= 1.1;
		nest->frac.zoom_y /= 1.1;
		nest->frac.display_shift *= 1.1;
	}
	nest->frac.x_min = tmp_x - (x / nest->frac.zoom_x);
	nest->frac.y_min = tmp_y - (x / nest->frac.zoom_y);
	ft_put_image_to_window(nest);
	return (0);
}
