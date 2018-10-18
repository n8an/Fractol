/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:33:21 by vnekhay           #+#    #+#             */
/*   Updated: 2018/03/31 22:48:17 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel(t_envs *f, int i, int j, int color)
{
	color = mlx_get_color_value(f->mlx, color);
	ft_memcpy(f->img_ptr + 4 * 1000 * j + i * 4,
			&color, sizeof(int));
}

void	sometext(t_envs *f)
{
	mlx_string_put(f->mlx, f->win, 735, 635, 0xA9F5BC, "Quit = Esc");
	mlx_string_put(f->mlx, f->win, 735, 655, 0x58D3F7, "Reset = Space");
	mlx_string_put(f->mlx, f->win, 735, 675, 0xFF0000, "Pause = P");
	mlx_string_put(f->mlx, f->win, 735, 695, 0xFF9900, "Move = ^/ v/ </ >");
	mlx_string_put(f->mlx, f->win, 735, 715, 0xFFFFFF, "Colour = 2/ 3");
	mlx_string_put(f->mlx, f->win, 735, 735, 0xFFFF00, "Zoom = scroll");
	mlx_string_put(f->mlx, f->win, 735, 755, 0x66FF00, "Iterations = +/ -");
	mlx_string_put(f->mlx, f->win, 735, 775, 0xFF00BF, "Psychedelic = 1");
}
