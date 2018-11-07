/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:42:27 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/07 15:28:20 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

void			fill_pixel(unsigned int *img, int x, int y, int i)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		/*
		if (i < 0)
			img[y * WIDTH + x] = 0xff00ff;
		else if (i == 0)
			img[y * WIDTH + x] = 0xffffff;
		else if (i <= 10)
			img[y * WIDTH + x] = 0xffffdd;
		else if (i <= 20)
			img[y * WIDTH + x] = 0xffff51;
		else if (i <= 25)
			img[y * WIDTH + x] = 0xffff15;
		else if (i <= 50)
			img[y * WIDTH + x] = 0xff7d23;
		else if (i <= 100)
			img[y * WIDTH + x] = 0xff0051;
		else 
			img[y * WIDTH + x] = 0xff140d;
			*/
		img[y * WIDTH + x] = (L_PINK * (i / 2));
	}
}


