/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:42:27 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/22 01:43:57 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

void			fill_pixel(unsigned int *img, int x, int y, int i)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		if (i <= 5)
			img[y * WIDTH + x] = (D_PINK + i);
		else if (i <= 10)
			img[y * WIDTH + x] = (D_PINK + i * 25);
		else if (i <= 15)
			img[y * WIDTH + x] = (D_PINK + i * 40);
		else if (i <= 25)
			img[y * WIDTH + x] = (D_PINK + i);
		else if (i <= 50)
			img[y * WIDTH + x] = (0xc94cace + i);
		else
			img[y * WIDTH + x] = (GREY + i * i);
	}
}
