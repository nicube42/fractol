/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:12:43 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/03 16:12:53 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_init_mlx(t_nest *nest)
{
	nest->frac.mlx = mlx_init();
	if (!nest->frac.mlx)
		ft_error(nest);
	nest->frac.mlx_win = mlx_new_window(nest->frac.mlx, nest->frac.window_width,
			nest->frac.window_height, nest->frac.name);
	if (!nest->frac.mlx_win)
		ft_error(nest);
	ft_put_image_to_window(nest);
}

void	ft_select_fractal(t_nest *nest, int argc, char **argv)
{
	if (argc >= 2)
	{
		if (!ft_strncmp("1", argv[1], 1) && argc == 2)
			ft_mandelbrot_set(&nest->frac);
		else if (!ft_strncmp("2", argv[1], 1) && argc == 4)
		{
			nest->frac.c_real = ft_atof(argv[2]);
			nest->frac.c_im = ft_atof(argv[3]);
			ft_julia_set(&nest->frac);
		}
		else if (!ft_strncmp("2", argv[1], 1))
			ft_julia_text(nest);
		else if (!ft_strncmp("3", argv[1], 1) && argc == 2)
			ft_ship_set(&nest->frac);
		else
			ft_general_text(nest);
	}
	else
		ft_general_text(nest);
}

int	main(int argc, char **argv)
{
	t_nest	nest;

	nest.frac.window_width = 1200;
	nest.frac.window_height = 1200;
	ft_select_fractal(&nest, argc, argv);
	ft_init_mlx(&nest);
	mlx_hook(nest.frac.mlx_win, 17, 0L, ft_ok, &nest);
	mlx_key_hook(nest.frac.mlx_win, ft_key_hook, &nest);
	mlx_mouse_hook(nest.frac.mlx_win, ft_zoom_hook, &nest);
	ft_put_image_to_window(&nest);
	mlx_loop(nest.frac.mlx);
}
