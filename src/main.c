/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:20:43 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/07 15:25:21 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"
#include "../includes/fractol.h"
#include <stdio.h> // testing

int				deal_key(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == ESC)
		exit(SUCCESS);
	return (SUCCESS);
}

int				set_fractal(t_mlx *mlx, char *fractal_name)
{
	if (!fractal_name || !mlx)
		return (INVAL_FRACTAL_ERR);	
	if ((ft_strcmp(fractal_name, "Julia") == 0) || 
			(ft_strcmp(fractal_name, "julia") == 0))
		if(fractal_draw_julia(mlx) < 0 )
			return(DRAW_ERR);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}

int				fractol_start(char *fractal_name)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (INVAL_MEM_ERR);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.pixel_pos = (unsigned int *)mlx_get_data_addr(mlx->img.img_ptr
			, &(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	if (set_fractal(mlx, fractal_name) < 0)
		return (INVAL_FRACTAL_ERR);
	//initialize_menu(mlx);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./fractol <file> ::: Available files: Julia, Mandelbrot, __x__\n");
		return (-1);
	}
	else if(fractol_start(argv[1]) < 0)
		return (-1);
	return (0);
}
