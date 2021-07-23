/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:09:52 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/06 11:15:55 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	rvalue;

	rvalue = 0;
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	if (s1[i] > s2[i])
		rvalue = 1;
	if (s1[i] < s2[i])
		rvalue = -1;
	return (rvalue);
}

void	ft_sort_tab(char **tab, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = size;
	while (i > 1)
	{
		j = 1;
		while (j < i - 1)
		{
			if (ft_strcmp(tab[j + 1], tab[j]) < 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_sort_tab(argv, argc);
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
