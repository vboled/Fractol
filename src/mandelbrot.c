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

int		is_limited(double x, double y, int n)
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
			return (i);
		i++;
	}
	return (i);
}

void	circle(t_frac *frac)
{
	double x;
	double y;

	frac->old_x = (double)(frac->mouse_x - 400) / frac->old_scale;
	double new_x = (double)(- 350) / frac->scale;
	double dx = new_x - frac->old_x;
	frac->old_y = (double)(frac->mouse_y - 400) / frac->old_scale;
	double new_y = (double)(- 350) / frac->scale;
	double dy = new_y - frac->old_y;
	for (int i = 0; i < 800; i++)
	{
		y = (double)(i - 400) / frac->scale - dy;
		for (int j = 0; j < 800; j++)
		{
			x = (double)(j - 400) / frac->scale - dx;
			if (i == 50 && j == 50)
			{
				printf("old_x = %f, ", frac->old_x);
				printf("new_x = %f\n", x);
				printf("old_x = %f, ", frac->old_y);
				printf("new_x = %f\n\n", y);
			}
			if (x * x + y * y <= 1)
				frac->pix_m[i * 800 + j] = 0;
			else
				frac->pix_m[i * 800 + j] = 0xFF0000;
		}
	}
}

void	put_mand(t_frac *frac)
{
	int i;
	int j;
	double x;
	double y;

	i = 0;
	printf("(%d, %d)\n", frac->mouse_x, frac->mouse_y);
	while (i < 800)
	{
		j = 0;
		y = (i - frac->mouse_y);
		y /= frac->scale;
		while (j < 800)
		{
			x = j - frac->mouse_x;
			x /= frac->scale;
			frac->pix_m[j * 800 + i] = put_color(frac, is_limited(x, y, frac->num_of_iter));
			j++;
		}
		i++;
	}
}