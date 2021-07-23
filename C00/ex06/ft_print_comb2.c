/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 01:05:58 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/06 22:48:48 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_value(char a, char b)
{
	int	i;
	int	j;

	i = a - 48;
	j = b - 48;
	return (i * 10 + j);
}

void	ft_combine(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a != '9' || b != '8' || c != '9' || d != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0' - 1;
	while (a++ < '9')
	{
		b = '0' - 1;
		while (b++ < '9')
		{
			c = a - 1;
			while (c++ < '9')
			{
				d = '0' - 1;
				while (d++ < '9')
				{
					if (ft_value(a, b) < ft_value(c, d))
					{
						ft_combine(a, b, c, d);
					}
				}
			}
		}
	}
}
