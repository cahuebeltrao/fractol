/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:20:43 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/22 01:57:50 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"
#include "../includes/fractol.h"

int	set_fractal(t_mlx *mlx, char *fractal_name)
{
	if (!fractal_name || !mlx)
		return (INVAL_FRACTAL_ERR);
	if (mlx->fractol_type == JULIA)
		if (set_julia(mlx) < 0)
			return (DRAW_ERR);
	if (mlx->fractol_type == MANDELBROT)
		if (set_mandelbrot(mlx) < 0)
			return (DRAW_ERR);
	if (mlx->fractol_type == MINE)
		if (set_mine(mlx) < 0)
			return (DRAW_ERR);
	return (SUCCESS);
}

int	fractol_check(t_mlx *mlx, char *fractal_name)
{
	if (!fractal_name || !mlx)
		return (INVAL_FRACTAL_ERR);
	if ((ft_strcmp(fractal_name, "Julia") == 0) ||
			(ft_strcmp(fractal_name, "julia") == 0))
	{
		mlx->fractol_type = JULIA;
		return (SUCCESS);
	}
	else if ((ft_strcmp(fractal_name, "Mandelbrot") == 0) ||
			(ft_strcmp(fractal_name, "mandelbrot") == 0))
	{
		mlx->fractol_type = MANDELBROT;
		return (SUCCESS);
	}
	else if ((ft_strcmp(fractal_name, "Mine") == 0) ||
			(ft_strcmp(fractal_name, "mine") == 0))
	{
		mlx->fractol_type = MINE;
		return (SUCCESS);
	}
	return (INVAL_FRACTAL_ERR);
}

int	fractol_start(t_mlx *mlx, char *fractal_name)
{
	if (fractol_check(mlx, fractal_name) < 0)
		return (INVAL_FRACTAL_ERR);
	if (!(mlx->mlx_ptr))
	{
		mlx->mlx_ptr = mlx_init();
	}
	if (!(mlx->win_ptr))
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	}
	if (mlx->img.img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
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
	mlx->params.zoom = zoom_set(fractal_name);
	mlx->params.move_x = DEF_MOVE_X;
	mlx->params.move_y = DEF_MOVE_Y;
	mlx->params.mouse_x = 0;
	mlx->params.mouse_y = 0;
	mlx->params.cRe = DEF_CRE;
	mlx->params.cIm = DEF_CIM;
	if (fractol_start(mlx, fractal_name) < 0)
	{
		ft_putstr("Invalid fractal name\n");
		return (INVAL_FRACTAL_ERR);
	}
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_hook, mlx);
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
