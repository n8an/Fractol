/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:32:46 by vnekhay           #+#    #+#             */
/*   Updated: 2018/03/31 22:29:02 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		additional_button(int button, t_envs *f)
{
	if (button == 19)
		f->color = 10050;
	else if (button == 20)
		f->color = 20050;
	else if (button == 35)
	{
		if (f->jmouse == 1)
			f->jmouse = 0;
		else
			f->jmouse = 1;
	}
	return (0);
}

int				button(int button, t_envs *f)
{
	if (button == 53)
		exit(1);
	else if (button == 18)
		f->color = 1677216;
	else if (button == 49)
		the_chosen_one(f);
	else if (button == 69)
		f->max_circles = f->max_circles + 10;
	else if (button == 78)
		f->max_circles = f->max_circles - 10;
	else if (button == 123)
		f->x1 -= 30 / f->closer;
	else if (button == 124)
		f->x1 += 30 / f->closer;
	else if (button == 125)
		f->y1 += 30 / f->closer;
	else if (button == 126)
		f->y1 -= 30 / f->closer;
	additional_button(button, f);
	multithreading(f);
	return (0);
}

static	void	zoom_increment(int i, int j, t_envs *f)
{
	f->x2 = i;
	f->y2 = j;
	f->x1 = (i / f->closer + f->x1) - ((f->closer * 1.2) / 2);
	f->x1 += ((f->closer * 1.2) / 2) - (i / (f->closer * 1.2));
	f->y1 = (j / f->closer + f->y1) - ((f->closer * 1.2) / 2);
	f->y1 += ((f->closer * 1.2) / 2) - (j / (f->closer * 1.2));
	f->closer *= 1.2;
	f->max_circles++;
}

static	void	zoom_decrement(t_envs *f)
{
	f->x1 = (f->x2 / f->closer + f->x1) - ((f->closer / 1.2) / 2);
	f->x1 += ((f->closer / 1.2) / 2) - (f->x2 / (f->closer / 1.2));
	f->y1 = (f->y2 / f->closer + f->y1) - ((f->closer / 1.2) / 2);
	f->y1 += ((f->closer / 1.2) / 2) - (f->y2 / (f->closer / 1.2));
	f->closer /= 1.2;
	f->max_circles--;
}

int				mouse_env(int index, int i, int j, t_envs *data)
{
	if (index == 4 || index == 1)
		zoom_increment(i, j, data);
	else if (index == 5 || index == 2)
		zoom_decrement(data);
	multithreading(data);
	return (0);
}
