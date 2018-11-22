/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:20:43 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/22 01:02:45 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"
#include "../includes/fractol.h"

int	deal_key(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == ESC)
		exit(SUCCESS);
	return (SUCCESS);
}

int	mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == 4)
		mlx->params.zoom += 0.1;
	else if (key == 5 && mlx->params.zoom > 1.0)
		mlx->params.zoom -= 0.1;
	if (mlx->fractol_type == JULIA)
		fractol_start(mlx, "julia");
	else if (mlx->fractol_type == MANDELBROT)
		fractol_start(mlx, "mandelbrot");
	else if (mlx->fractol_type == MINE)
		fractol_start(mlx, "mine");
	return (0);
}
