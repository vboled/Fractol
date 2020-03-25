/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:02:41 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 14:02:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_c(int key, t_frac *frac)
{
	if (key == 102)
		frac->c_x += 0.001;
	else if (key == 118)
		frac->c_x -= 0.001;
	else if (key == 103)
		frac->c_y += 0.001;
	else
		frac->c_y -= 0.001;
}

int		mouse_hook(int key, int x, int y, void *param)
{
	if (key == 4 || key == 5)
		scale_mouse(param, key, x, y);
	create_mlx_image(param);
	return (0);
}

void	destroy_window(t_frac *frac)
{
	t_frac *tmp;
	int type;

	type = frac->type;
	frac->type = -1;
	tmp = frac->head;
	while (tmp)
	{
		if (tmp->type != -1)
		{
			mlx_destroy_window(frac->mlx, frac->win);
			return ;
		}
		tmp = tmp->next;
	}
	free_list_frac(frac->head);
	write(1, "EXIT\n", 5);
	exit (0);
}

int		deal_hook(int key, t_frac *param)
{
	if (key == 65307) //53
		destroy_window(param);
	if (param->type != -1)
	{
		if (key == 102 || key == 98 || key == 118 || key == 103)
			change_c(key, param);
		if (key >= 65361 && key <= 65364) //123 126
			shift(param, key, 0.05);
		if (key == 65451 || key == 65453) //69 78
			scale_key(param, key);
		if (key == 97 || key == 122) // A, Z
			change_iter(param, key);
		create_mlx_image(param);
	}
	return (0);
}
