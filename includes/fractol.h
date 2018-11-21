/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:26:41 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/21 23:18:58 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 500
# define WIDTH 500

# define SUCCESS 1
# define INVAL_FRACTAL_ERR -2
# define INVAL_MEM_ERR -3
# define DRAW_ERR -4

# define ESC 53

# define L_PINK 0xf6c4d2
# define D_PINK 0xbe3782
# define L_BLUE 0x3697dd

# define DEF_ZOOM 1
# define DEF_MOVE_X 0
# define DEF_MOVE_Y 0
# define DEF_CRE (-0.73)
# define DEF_CIM 0.27015

# define Q 12
# define E 14

# define POINTER_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

# define JULIA 1
# define MANDELBROT 2

typedef	struct	s_params
{
	float			zoom;
	int				move_x;
	int				move_y;
	int				mouse_x;
	int				mouse_y;
	double			cRe;
	double			cIm;
}				t_params;

typedef struct	s_mandelbrot
{
	double			pr;
	double			pi;
	double			new_Re;
	double			new_Im;
	double			old_Re;
	double			old_Im;
	float			zoom;
	int				move_x;
	int				move_y;
	int				x;
	int				y;
	int				i;
	int				max_iterations;
}				t_mandelbrot;

typedef struct	s_julia
{
	float			zoom;
	int				move_x;
	int				move_y;
	double			cRe;
	double			cIm;
	int				x;
	int				y;
	double			re;
	double			im;
	double			old_Re;
	double			old_Im;
	int				max_iterations;
}				t_julia;

typedef struct	s_img
{
	void			*img_ptr;
	unsigned int	*pixel_pos;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol_type;
	t_params	params;
	t_img		img;
}				t_mlx;

void			fill_pixel(unsigned int *img, int x, int y, int i);

void			fractal_draw_julia(t_mlx *mlx, t_julia julia);

int				set_julia(t_mlx *mlx);

void			fractol_draw_mandelbrot(t_mlx *mlx, t_mandelbrot mandelbrot);

int				set_mandelbrot(t_mlx *mlx);

int				move(int x, int y, t_mlx*mlx);

int				fractol_start(t_mlx *mlx, char *fractal_name);

#endif
