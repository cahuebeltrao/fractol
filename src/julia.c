/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:52:18 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/07 15:30:04 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
int	fractal_draw_julia(t_mlx *mlx)
{
	// each iteration it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	double cRe, cIm;	// Real and imaginary part of the constant c, determinate shape of the julia set
	double newRe, newIm, oldRe, oldIm;
	double zoom = 1, moveX = 0, moveY = 0; //you can change to zoom and change position
	int		color;//ColorRGB color;
	int		maxIterations = 300;
	int		i;
	int		x, y;
	

	cRe = -0.7;
	cIm = 0.27015;
	y = 0;	
	//for(int y = 0; y < HEIGHT; y++)
	while(y < HEIGHT)
	{
	//for(int x = 0; x < WIDTH; x++)
		x = 0;
		while(x < WIDTH)
		{
			newRe = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
			newIm = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY;
			//i will represnet the number of iterations
			for(i = 0; i < maxIterations; i++)
			{
				//remember values
				oldRe = newRe;
				oldIm = newIm;
				//the acutla iteration, real and imaginary parts calculated
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				// if the point is outside the circle with radius 2: stop
				if((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			fill_pixel(mlx->img.pixel_pos, x, y, i);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
