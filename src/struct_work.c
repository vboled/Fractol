#include "fractol.h"

int		add_frac(t_frac **frac, int type)
{
	t_frac	*tmp;

	if (!(*frac))
	{
		if (!(*frac = (t_frac *)malloc(sizeof(t_frac))))
			return (0);
		frac_init(*frac, type, NULL);
		return (1);
	}
	tmp = *frac;
	while ((*frac)->next)
		*frac = (*frac)->next;
	if (!((*frac)->next = (t_frac *)malloc(sizeof(t_frac))))
		return (0);
	frac_init((*frac)->next, type, (*frac)->mlx);
	*frac = tmp;
	return (1);
}

void	frac_init(t_frac *frac, int type, void *mlx)
{
	frac->type = type;
	frac->next = NULL;
	frac->shift_x = 0;
	frac->shift_y = 0;
	frac->mouse_x = 400;
	frac->mouse_y = 500;
	frac->num_of_iter = 100;
	frac->color_scheme = 1;
	frac->change_x = 1;
	frac->scale = 200;
	frac->c_x = -0.8;
	frac->c_y = 0.156;
	frac->old_scale = frac->scale;
	if (mlx)
		frac->mlx = mlx;
	else
		frac->mlx = mlx_init();	
	frac->win = mlx_new_window(frac->mlx, WIDTH + 405, WIDTH + 100, "win1");
	frac->img = mlx_new_image(frac->mlx, WIDTH, WIDTH);
}

void	free_list_frac(t_frac *frac)
{
	t_frac *tmp;

	while (frac)
	{
		tmp = frac->next;
		if (frac->mlx)
			free(frac->mlx);
		// if (frac->win)
		// 	free(frac->win);
		// if (frac->img)
		// 	free(frac->img);
		// if (frac->pix_m)
		// 	free(frac->pix_m);
		free(frac);
		frac = tmp;
	}
	return ;
}
