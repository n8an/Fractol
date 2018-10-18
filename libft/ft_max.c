/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 07:30:58 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 07:32:23 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int len)
{
	int i;
	int j;

	j = 0;
	i = tab[j];
	while (j < len)
	{
		if (tab[j] > i)
			i = tab[j];
		j++;
	}
	return (i);
}
