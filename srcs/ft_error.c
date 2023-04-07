/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:12:30 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/03 16:12:35 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_clean_exit(t_nest *nest)
{
	if (nest->img.img)
		mlx_destroy_image(nest->frac.mlx, nest->img.img);
	if (nest->frac.mlx_win)
		mlx_destroy_window(nest->frac.mlx, nest->frac.mlx_win);
}

void	ft_error(t_nest *nest)
{
	(void) nest;
	ft_printf("\nerror\n");
	exit(1);
}

int	ft_ok(t_nest *nest)
{
	ft_clean_exit(nest);
	exit(0);
	return (0);
}

void	ft_julia_text(t_nest *nest)
{
	(void) nest;
	ft_printf("Dans le cas de l'ensemble de Julia, il faut egalement ");
	ft_printf("ajouter deux chiffres \n");
	ft_printf("en 2eme et 3eme argument. \nExemples notables : ");
	ft_printf("0.3/0.5   0.285/0.01   ");
	ft_printf("0.285/0.013   -0.4/0.6\n");
	exit(1);
}

void	ft_general_text(t_nest *nest)
{
	(void) nest;
	ft_printf("Selectionner la fractale de Mandelbrot, de Julia ou ");
	ft_printf("Burning Ship en \n");
	ft_printf("entrant respectivement 1 ou 2 ou 3 en premier ");
	ft_printf("argument.\n\n");
	exit(1);
}
