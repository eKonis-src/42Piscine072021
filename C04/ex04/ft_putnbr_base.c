/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:51:17 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/15 15:19:53 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 31)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	n;
	unsigned int	b;

	if (ft_check_base(base))
	{
		b = ft_strlen(base);
		if (nb < 0)
		{
			ft_putchar('-');
			n = (unsigned int) -nb;
		}
		else
			n = (unsigned int)nb;
		if (n >= b)
		{
			ft_putnbr_base(n / b, base);
			ft_putnbr_base(n % b, base);
		}
		else
			ft_putchar(base[n]);
	}
}

int	main(void)
{
	ft_putnbr_base(416534,"01");
}
