/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:39:30 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 17:39:31 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_mand(double x, double y, int n)
{
	int i;
	double z_x;
	double z_y;
	double tmp_x;

	i = 0;
	z_x = x;
	z_y = y;
	while (i < n)
	{
		tmp_x = z_x * z_x - z_y * z_y + x;
		z_y = 2 * z_x * z_y + y;
		z_x = tmp_x;
		if ((z_x * z_x + z_y * z_y) > 4)
			break ;
		i++;
	}
	return (i);
}

int		is_julia(double x, double y, t_frac *frac)
{
	int i;
	double z_x;
	double z_y;
	double tmp_x;
	double R;

	i = 0;
	z_x = x;
	z_y = y;
	R = (1 + sqrt(1 + 4 * sqrt(frac->c_x * frac->c_x + frac->c_y * frac->c_y))) / 2;
	while (i < frac->num_of_iter)
	{
		tmp_x = z_x * z_x - z_y * z_y + frac->c_x;
		z_y = 2 * z_x * z_y + frac->c_y;
		z_x = tmp_x;
		if (z_x * z_x + z_y * z_y  > R * R)
			return (i);
		i++;
	}
	return (i);
}

void	julia(t_frac *frac)
{
	int i;
	int j;
	double x;
	double y;

	i = 0;
	// printf("c_x = %f, c_y = %f\n\n", frac->c_x, frac->c_y);
	while (i < WIDTH)
	{
		j = 0;
		y = (i - WIDTH / 2);
		y /= frac->scale;
		while (j < WIDTH)
		{
			x = j - WIDTH / 2;
			x /= frac->scale;
			if (is_julia(x, y, frac) < frac->num_of_iter)
				frac->pix_m[i * WIDTH + j] = 0xFF0000;
			else
				frac->pix_m[i * WIDTH + j] = 0x0000FF;			
		//	frac->pix_m[i * WIDTH + j] = put_color(frac, is_limited(x, y, frac->num_of_iter, 10));
			j++;
		}
		i++;
	}
}

void	circle(t_frac *frac)
{
	double x;
	double y;
	double old_x;
	double old_y;
	double new_x;
	double new_y;

	new_x = (double)(frac->mouse_x - 400) / frac->scale;
	new_y = (double)(frac->mouse_y - 400) / frac->scale;
	old_x = (double)(frac->mouse_x - 400) / frac->old_scale;
	old_y = (double)(frac->mouse_y - 400) / frac->old_scale;
	double dx = new_x - old_x;
	double dy = new_y - old_y;
	for (int i = 0; i < WIDTH; i++)
	{
		y = (double)(i - 400) / frac->scale - dy;
		for (int j = 0; j < WIDTH; j++)
		{
			x = (double)(j - 400) / frac->scale - dx;
			if (i == 50 && j == 50)
			{
				// printf("x = %f, ", x);
				// printf("y = %f\n", y);
				// printf("new_x = %f, ", new_x);
				// printf("new_y = %f\n", new_y);
				// printf("old_x = %f, ", old_x);
				// printf("old_y = %f\n\n", old_y);
			}
			if (x * x + y * y <= 1)
				frac->pix_m[i * WIDTH + j] = 0;
			else
				frac->pix_m[i * WIDTH + j] = 0xFF0000;
		}
	}
}

void	mandelbrot(t_frac *frac)
{
	int i;
	int j;
	double x;
	double y;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		y = (i - WIDTH / 2);
		y /= frac->scale;
		while (j < WIDTH)
		{
			x = j - WIDTH / 2;
			x /= frac->scale;
			frac->pix_m[i * WIDTH + j] = put_color(frac, is_mand(x, y, frac->num_of_iter));
			j++;
		}
		i++;
	}
}