/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:33:01 by vnekhay           #+#    #+#             */
/*   Updated: 2018/03/31 22:53:26 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				error(void)
{
	ft_putendl("./fractol Mandelbrot, Julia, BurningShip");
	ft_putendl("<== You should choose the name of the fractol here");
	return (0);
}

static	void	map_envs(t_envs *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1000, 800, "Fract'ol");
	f->img = mlx_new_image(f->mlx, 1000, 1000);
	f->img_ptr = mlx_get_data_addr(f->img,\
			&f->bppixel, &f->slines, &f->e);
}

void			the_chosen_one(t_envs *f)
{
	if (f->fract == 0)
		mandelbrot_envs(f);
	else if (f->fract == 1)
		julia_envs(f);
	else if (f->fract == 2)
		burningship_envs(f);
	multithreading(f);
}

void			multithreading(t_envs *f)
{
	if (f->max_circles < 0)
		f->max_circles = 0;
	if (f->fract == 0)
		multimandelbrot(f);
	else if (f->fract == 1)
		multijulia(f);
	else if (f->fract == 2)
		multiburningship(f);
	sometext(f);
}

int				main(int ac, char **av)
{
	t_envs	*f;

	if (!(f = (t_envs *)malloc(sizeof(t_envs))))
		return (error());
	if (ac != 2)
		return (error());
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		f->fract = 0;
	else if (ft_strcmp(av[1], "Julia") == 0)
		f->fract = 1;
	else if (ft_strcmp(av[1], "BurningShip") == 0)
		f->fract = 2;
	else
		return (error());
	map_envs(f);
	the_chosen_one(f);
	mlx_hook(f->win, 6, 1L, mouse_julia, f);
	mlx_key_hook(f->win, button, f);
	mlx_mouse_hook(f->win, mouse_env, f);
	mlx_loop(f->mlx);
	return (0);
}
