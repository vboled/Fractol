/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:48:18 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 13:53:23 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_frac frac;

	ft_bzero(&frac, sizeof(t_frac));
	frac_init(&frac);
	argc++;
	argv++;
	mlx_hook(frac.win, 2, 0, deal_hook, &frac);
	mlx_hook(frac.win, 4, 0, mouse_hook, &frac);
	// printf("%d\n", frac.num_of_iter);
	create_mlx_image(&frac);
	mlx_loop(frac.mlx);
	return (0);
}
