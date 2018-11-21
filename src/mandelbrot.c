/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:52:18 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/21 22:16:04 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include <mlx.h>

void	ft_reset_mandel(t_mandelbrot *m)
{
	m->new_Re = 0;
	m->new_Im = 0;
	m->old_Re = 0;
	m->old_Im = 0;
}

void	fractal_draw_mandelbrot(t_mlx *mlx, t_mandelbrot m)
{
	m.y = 0;
	while (m.y < HEIGHT)
	{
		m.x = 0;
		while (m.x < WIDTH)
		{
			m.pr = 1.5 * (m.x - WIDTH / 2) / (0.5 * m.zoom * WIDTH) + -0.5;
			m.pi = (m.y - HEIGHT / 2) / (0.5 * m.zoom * HEIGHT) + m.move_y;
			m.i = 0;
			ft_reset_mandel(&m);
			while (m.i++ < m.max_iterations)
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

int		set_mandelbrot(t_mlx *mlx)
{
	t_mandelbrot mandelbrot;

	mandelbrot.move_x = mlx->params.move_x;
	mandelbrot.move_y = mlx->params.move_y;
	mandelbrot.zoom = mlx->params.zoom;
	mandelbrot.new_Re = 0;
	mandelbrot.new_Im = 0;
	mandelbrot.old_Re = 0;
	mandelbrot.old_Im = 0;
	mandelbrot.max_iterations = 150;
	mandelbrot.x = 0;
	mandelbrot.y = 0;
	fractal_draw_mandelbrot(mlx, mandelbrot);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}
