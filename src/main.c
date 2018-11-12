/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:20:43 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/12 18:24:42 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"
#include "../includes/fractol.h"

#include <stdio.h> // DELETE

int	fractol_start(t_mlx *mlx, char *fractal_name);

int	deal_key(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == ESC)
		exit(SUCCESS);
	return (SUCCESS);
}

int	move(int x, int y, t_mlx *mlx)
{
	(void)mlx;
	if(mlx->params.mouse_x == 0 && mlx->params.mouse_y == 0)
	{
		mlx->params.mouse_x = x;
		mlx->params.mouse_y = y;
	}
	else if(mlx->params.mouse_x != 0 && mlx->params.mouse_y != 0)
	{
		if(x > (mlx->params.mouse_x + 5) || y > (mlx->params.mouse_y + 5))
		{
			mlx->params.mouse_x = x;
			mlx->params.mouse_y = y;
			if(mlx->params.cRe < DEF_CRE)
			{
				//mlx->params.zoom += 0.1;
				mlx->params.cRe += 0.005;
				mlx->params.cIm -= 0.0009;
				fractol_start(mlx, "julia");
			}
			return(SUCCESS);
		}	
		else if (x < (mlx->params.mouse_x - 5) || y < (mlx->params.mouse_y - 5))
		{
			mlx->params.mouse_x = x;
			mlx->params.mouse_y = y;
			if (mlx->params.cRe > -1.5)
			{
				//mlx->params.zoom -= 0.1;
				mlx->params.cRe -= 0.005;
				mlx->params.cIm += 0.00005;
				fractol_start(mlx, "julia");
			}
			return(SUCCESS);
		}
	}
	printf("%f\n", mlx->params.cRe);
	fflush(stdout);
	return (1);
}

int	set_fractal(t_mlx *mlx, char *fractal_name)
{
	if (!fractal_name || !mlx)
		return (INVAL_FRACTAL_ERR);
	if ((ft_strcmp(fractal_name, "Julia") == 0) ||
			(ft_strcmp(fractal_name, "julia") == 0))
		if (set_julia(mlx) < 0)
			return (DRAW_ERR);
	return (SUCCESS);
}

int	fractol_start(t_mlx *mlx, char *fractal_name)
{

	if(!(mlx->mlx_ptr))
	{
		mlx->mlx_ptr = mlx_init();
		ft_putstr("entrou mlx_init\n");
	}
	if(!(mlx->win_ptr))
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
		ft_putstr("entrou new window\n");
	}
	if(mlx->img.img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		ft_putstr("entrou pra destruir\n");
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.pixel_pos = (unsigned int *)mlx_get_data_addr(mlx->img.img_ptr
			, &(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	if (set_fractal(mlx, fractal_name) < 0)
		return (INVAL_FRACTAL_ERR);
	return (SUCCESS);
}

int	mlx_start(char *fractal_name)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (INVAL_MEM_ERR);
	mlx->params.zoom = DEF_ZOOM;
	mlx->params.move_x = DEF_MOVE_X;
	mlx->params.move_y = DEF_MOVE_Y;
	mlx->params.mouse_x = 0;
	mlx->params.mouse_y = 0;
	mlx->params.cRe = DEF_CRE;
	mlx->params.cIm = DEF_CIM;
	fractol_start(mlx, fractal_name);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_hook(mlx->win_ptr, MOTION_NOTIFY, POINTER_MOTION_MASK, move, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./fractol <fractal_name>");
		ft_putstr(" ::: Available fractals: Julia, Mandelbrot, __x__\n");
		return (-1);
	}
	else if (mlx_start(argv[1]) < 0)
		return (-1);
	return (0);
}
