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

#include "../includes/fractol.h"

int		mouse_hook(int key, int x, int y, void *param)
{
	if (key == 4 || key == 5)
		mouse_wheel(param, key, x, y);
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

void	change_role(t_frac *param)
{
	if (param->change_x == -1)
		param->change_x = 0;
	else if (param->change_x == 1)
		param->change_x = -1;
	else
		param->change_x = 1;
}