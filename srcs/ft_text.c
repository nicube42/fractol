/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:23:37 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/05 10:47:56 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_text(t_nest *nest)
{
	char	*iter;

	iter = ft_itoa(nest->frac.max_iter);
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 30,
		0xC0C0C0, "C = change color");
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 50,
		0xC0C0C0, "Up, down, left, right arrows = move");
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 70,
		0xC0C0C0, "Scroll up/down = zoom + / zoom -");
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 90,
		0xC0C0C0, "Max iteration = ");
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 120, 90,
		0xC0C0C0, iter);
	free (iter);
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 110,
		0xC0C0C0, "Q = Reduce iteration of 10");
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 130,
		0xC0C0C0, "W = Increase iteration of 10");
	mlx_string_put(nest->frac.mlx, nest->frac.mlx_win, 10, 150,
		0xC0C0C0, "ESC = quit");
}
