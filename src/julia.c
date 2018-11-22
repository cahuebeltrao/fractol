/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:52:18 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/21 23:32:37 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include <mlx.h>

void	fractal_draw_julia(t_mlx *mlx, t_julia j)
{
	int		i;

	j.y = 0;
	while (j.y < HEIGHT)
	{
		j.x = 0;
		while (j.x < WIDTH)
		{
			j.re = 1.5 * (j.x - WIDTH / 2) / (0.5 * j.zoom * WIDTH) + j.move_x;
			j.im = (j.y - HEIGHT / 2) / (0.5 * j.zoom * HEIGHT) + j.move_y;
			i = 0;
			while (i++ < j.max_iterations)
			{
				j.old_Re = j.re;
				j.old_Im = j.im;
				j.re = j.old_Re * j.old_Re - j.old_Im * j.old_Im + j.cRe;
				j.im = 2 * j.old_Re * j.old_Im + j.cIm;
				if ((j.re * j.re + j.im * j.im) > 4)
					break ;
			}
			fill_pixel(mlx->img.pixel_pos, j.x, j.y, i);
			j.x++;
		}
		j.y++;
	}
}

int		set_julia(t_mlx *mlx)
{
	t_julia julia;

	julia.zoom = mlx->params.zoom;
	julia.move_x = mlx->params.move_x;
	julia.move_y = mlx->params.move_y;
	julia.cRe = mlx->params.cRe;
	julia.cIm = mlx->params.cIm;
	julia.x = 0;
	julia.y = 0;
	julia.re = 0;
	julia.im = 0;
	julia.old_Re = 0;
	julia.old_Im = 0;
	julia.max_iterations = 150;
	fractal_draw_julia(mlx, julia);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}

int		const_increase(t_mlx *mlx, int x, int y)
{
	mlx->params.mouse_x = x;
	mlx->params.mouse_y = y;
	mlx->params.cRe += 0.005;
	fractol_start(mlx, "julia");
	return (SUCCESS);
}

int		const_decrease(t_mlx *mlx, int x, int y)
{
	mlx->params.mouse_x = x;
	mlx->params.mouse_y = y;
	mlx->params.cRe -= 0.005;
	fractol_start(mlx, "julia");
	return (SUCCESS);
}

int		move(int x, int y, t_mlx *mlx)
{
	if (mlx->params.mouse_x == 0 && mlx->params.mouse_y == 0 &&
			mlx->fractol_type == JULIA)
	{
		mlx->params.mouse_x = x;
		mlx->params.mouse_y = y;
	}
	else if (mlx->params.mouse_x != 0 && mlx->params.mouse_y != 0 &&
			mlx->fractol_type == JULIA)
	{
		if ((x > (mlx->params.mouse_x + 5) || y > (mlx->params.mouse_y + 5))
				&& x < WIDTH && y < HEIGHT
				&& x > 0 && y > 0)
			const_increase(mlx, x, y);
		else if ((x < (mlx->params.mouse_x - 5)
				|| y < (mlx->params.mouse_y - 5))
				&& x < WIDTH && y < HEIGHT
				&& x > 0 && y > 0)
			const_decrease(mlx, x, y);
	}
	return (SUCCESS);
}
