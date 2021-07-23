/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:37:05 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/07 16:47:36 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **tab, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*tab = NULL;
		return (0);
	}
	*tab = malloc(sizeof(int) * (max - min));
	if (!(*tab))
		return (-1);
	while (min < max)
	{
		tab[0][i] = min++;
		i++;
	}
	return (i);
}
