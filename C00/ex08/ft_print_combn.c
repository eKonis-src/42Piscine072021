/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:22:26 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/05 00:36:50 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	*fill_Tab(int *tab, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		tab[i] = i - 1;
	return (tab);
}

void	ft_combine(int *tab, int n, int f)
{
	int		i;
	char	str[10];

	i = 0;
	while (i < n - 1)
	{
		if (tab[i] >= tab[i + 1])
			return ;
		str[i] = tab[i] + '0';
		i++;
	}
	str[i] = tab[i] + '0';
	i = -1;
	while (i++ < n - 1)
		if (tab[i] != i)
			f = 1;
	if (f)
		ft_putstr(", ", 2);
	ft_putstr(str, n);
}

void	ft_print_combr(int *tab, int n, int r)
{
	if (r >= n - 1)
	{
		while (tab[r] < 9)
		{
			tab[r]++;
			ft_combine(tab, n, 0);
		}
		tab[r] = 0;
	}
	else
	{
		while (tab[r] < 9)
		{
			tab[r]++;
			ft_print_combr(tab, n, r + 1);
		}
		tab[r] = 0;
	}
}

void	ft_print_combn(int n)
{
	int	digits[9];

	fill_Tab(digits, n);
	ft_print_combr(digits, n, 0);
}