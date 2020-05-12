/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:29:08 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/11 14:29:09 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_hook(int key, t_frac *param)
{
	if (key == 53)
		destroy_window(param);
	if (param->type != -1)
	{
		if (key == 113)
			change_role(param);
		if (key >= 123 && key <= 126)
			shift(param, key, 0.05);
		if (key == 69 || key == 78)
			scale_key(param, key);
		if (key == 97 || key == 122)	
			change_iter(param, key);
		create_mlx_image(param);
	}
	return (0);
}