/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:32:53 by vnekhay           #+#    #+#             */
/*   Updated: 2018/03/31 22:36:59 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_julia(int x, int y, t_envs *f)
{
	if (f->fract == 1 && f->jmouse == 1)
	{
		f->x3 = x * 2;
		f->y3 = y * 2 - 800;
		multithreading(f);
	}
	return (0);
}

void			julia_envs(t_envs *f)
{
	f->max_circles = 50;
	f->closer = 200;
	f->x1 = -2.0;
	f->y1 = -1.9;
	f->color = 1600;
	f->x3 = 0.285;
	f->y3 = 0.01;
	f->jmouse = 1;
}

static	void	multitudejulia(t_envs *f)
{
	f->x4 = f->x / f->closer + f->x1;
	f->y4 = f->y / f->closer + f->y1;
	f->circles = 0;
	while (f->x4 * f->x4 + f->y4
			* f->y4 < 4 && f->circles < f->max_circles)
	{
		f->temp = f->x4;
		f->x4 = f->x4 * f->x4 - \
			f->y4 * f->y4 - 0.8 + (f->x3 / 1000);
		f->y4 = 2 * f->y4 * f->temp + f->y3 / 1000;
		f->circles++;
	}
	if (f->circles == f->max_circles)
		putpixel(f, f->x, f->y, 0x000000);
	else
		putpixel(f, f->x, f->y, (f->color * f->circles));
}

static	void	*start_julia(void *mas)
{
	t_envs		*f;
	double		temp;

	f = (t_envs *)mas;
	f->x = 0;
	temp = f->y;
	while (f->x < 1000)
	{
		f->y = temp;
		while (f->y < f->y_m)
		{
			multitudejulia(f);
			f->y++;
		}
		f->x++;
	}
	return (mas);
}

void			multijulia(t_envs *f)
{
	t_envs		mas[8];
	pthread_t	tab[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&mas[i], (void*)f, sizeof(t_envs));
		mas[i].y = 100 * i;
		mas[i].y_m = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&tab[i - 1], NULL, start_julia, &mas[i - 1]);
	while (i--)
		pthread_join(tab[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
