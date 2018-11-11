/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:52:18 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/11 18:05:38 by cbeltrao         ###   ########.fr       */
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
	fractal_draw_julia(mlx, julia);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}
