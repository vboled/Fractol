/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:49:34 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 13:50:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
# include "../libft/libft.h"
#include <stdio.h>

typedef struct			s_frac
{
	struct s_frac		*next;
	struct s_frac		*head;
	void				*mlx;
	void				*win;
	void				*img;
	int					*pix_m;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	double				shift_x;
	double				shift_y;
	int					scale;
	int					old_scale;
	int					pix_m_size;
	int					color_scheme;
	int					mouse_x;
	int					mouse_y;
	double				c_x;
	double				c_y;
	int					change_x;
	int					type;
	int					num_of_iter;
	int					num_of_str;
}						t_frac;

int						deal_hook(int key, t_frac *param);
void					frac_init(t_frac *frac, int type, void *mlx);
void					shift(t_frac *frac, int key, double step);
int						mem_alloc(t_frac *frac);
void					free_list_frac(t_frac *frac);
void					scale_key(t_frac *frac, int key);
void					create_mlx_image(t_frac *frac);
void					mandelbrot(t_frac *frac);
int						add_frac(t_frac **frac, int type);
int						mouse_hook(int key, int x, int y, void *param);
int						put_color(t_frac *frac, int iter);
void					mouse_wheel(t_frac *frac, int key, int x, int y);
void					change_iter(t_frac *frac, int key);
void					julia(t_frac *frac);
void					circle(t_frac *frac);//t);
void					print_param(t_frac *frac);//
#endif
