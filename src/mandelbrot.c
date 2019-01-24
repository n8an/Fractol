/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PIDR<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:33:08 by vnekhay           #+#    #+#             */
/*   Updated: 2018/03/31 22:40:48 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			mandelbrot_envs(t_envs *f)
{
	f->max_circles = 50;
	f->closer = 300;
	f->x1 = -2.05;
	f->y1 = -1.3;
	f->color = 11600;
}

static	void	multitudemandelbrot(t_envs *f)
{
	f->x3 = f->x / f->closer + f->x1;
	f->y3 = f->y / f->closer + f->y1;
	f->x4 = 0;
	f->y4 = 0;
	f->circles = 0;
	while (f->x4 * f->x4 + f->y4 *
			f->y4 < 4 && f->circles < f->max_circles)
	{
		f->temp = f->x4;
		f->x4 = f->x4 * f->x4 -
			f->y4 * f->y4 + f->x3;
		f->y4 = 2 * f->y4 * f->temp + f->y3;
		f->circles++;
	}
	if (f->circles == f->max_circles)
		putpixel(f, f->x, f->y, 0x000000);
	else
		putpixel(f, f->x, f->y, (f->color * f->circles));
}

static	void	*start_mandelbrot(void *mas)
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
			multitudemandelbrot(f);
			f->y++;
		}
		f->x++;
	}
	return (mas);
}

void			multimandelbrot(t_envs *f)
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
		pthread_create(&tab[i - 1], NULL, start_mandelbrot, &mas[i - 1]);
	while (i--)
		pthread_join(tab[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
