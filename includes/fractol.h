/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:26:41 by cbeltrao          #+#    #+#             */
/*   Updated: 2018/11/07 15:23:02 by cbeltrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 600
# define WIDTH 800

# define SUCCESS 1
# define INVAL_FRACTAL_ERR -2
# define INVAL_MEM_ERR -3
# define DRAW_ERR -4

# define ESC 53

# define L_PINK 0xf6c4d2
# define D_PINK 0xbe3782
# define L_BLUE 0x3697dd

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_julia
{
	int				zoom;
	int				move_x;
	int				move_y;
	unsigned int	color;
}				t_julia;

typedef struct	s_fractal
{
	t_point		**p;
}				t_fractal;

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
	int			win_length;
	int			win_depth;
	t_img		img;
}				t_mlx;

void			fill_pixel(unsigned int *img, int x, int y, int i);

int				fractal_draw_julia(t_mlx *mlx);

#endif
