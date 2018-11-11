/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:42:27 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/07 16:04:00 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

void			fill_pixel(unsigned int *img, int x, int y, int i)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
		img[y * WIDTH + x] = (L_BLUE + (i * i * i * i));
}
