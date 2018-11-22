/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:56:47 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/22 02:01:01 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include <mlx.h>

int		zoom_set(char *fractal_name)
{
	if ((ft_strcmp(fractal_name, "mine") == 0) ||
			(ft_strcmp(fractal_name, "Mine") == 0))
		return (123);
	return (DEF_ZOOM);
}
