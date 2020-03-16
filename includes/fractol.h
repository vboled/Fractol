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
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct			s_frac
{
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
	double				old_x;
	double				old_y;
	int					num_of_iter;
}						t_frac;

int						deal_hook(int key, void *param);
void					frac_init(t_frac *frac);
void					shift(t_frac *frac, int key, double step);
int						mem_alloc(t_frac *frac);
void					free_struct(t_frac *frac);
void					scale_key(t_frac *frac, int key);
void					create_mlx_image(t_frac *frac);
void					put_mand(t_frac *frac);
int						mouse_hook(int key, int x, int y, void *param);
int						put_color(t_frac *frac, int iter);
void					scale_mouse(t_frac *frac, int key, int x, int y);
void					circle(t_frac *frac);//
#endif
