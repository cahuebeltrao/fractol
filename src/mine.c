/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:52:18 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/22 01:59:06 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include <mlx.h>

void	fractal_draw_mine(t_mlx *mlx, t_mandelbrot m)
{
	m.y = 0;
	while (m.y < HEIGHT)
	{
		m.x = 0;
		while (m.x < WIDTH)
		{
			m.pr = 1.5 * (m.x - WIDTH / 2) / (0.5 * m.zoom * WIDTH) + -0.743153;
			m.pi = (m.y - HEIGHT / 2) / (0.5 * m.zoom * HEIGHT) + -0.1394057861;
			m.i = 0;
			ft_reset_mandel(&m);
			while (m.i++ < 150)
			{
				m.old_Re = m.new_Re;
				m.old_Im = m.new_Im;
				m.new_Re = m.old_Re * m.old_Re - m.old_Im * m.old_Im + m.pr;
				m.new_Im = 2 * m.old_Re * m.old_Im + m.pi;
				if ((m.new_Re * m.new_Re + m.new_Im * m.new_Im) > 4)
					break ;
			}
			fill_pixel(mlx->img.pixel_pos, m.x, m.y, m.i);
			m.x++;
		}
		m.y++;
	}
}

int		set_mine(t_mlx *mlx)
{
	t_mandelbrot mine;

	mine.move_x = mlx->params.move_x;
	mine.move_y = mlx->params.move_y;
	mine.zoom = mlx->params.zoom;
	mine.new_Re = 0;
	mine.new_Im = 0;
	mine.old_Re = 0;
	mine.old_Im = 0;
	mine.max_iterations = 150;
	mine.x = 0;
	mine.y = 0;
	fractal_draw_mine(mlx, mine);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}
