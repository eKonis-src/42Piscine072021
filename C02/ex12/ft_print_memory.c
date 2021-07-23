/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:22:26 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/19 18:37:25 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnstr(char *str, char n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] < 32 || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	ft_find_lenght(unsigned long i)
{
	int				radix;
	unsigned long	pow;

	radix = 1;
	pow = 16;
	while (i >= pow)
	{
		pow *= 16;
		radix += 1;
	}
	return (radix);
}

void	ft_print_mem(char *str, char *base)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] && j < 16)
		j++;
	i = 0;
	while (i < 16)
	{
		if (i < j)
		{
			write(1, &base[str[i] / 16], 1);
			write(1, &base[str[i] % 16], 1);
		}
		else
			write(1, " ", 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_hexa_add(unsigned long add, char *base)
{
	unsigned long	n;
	unsigned long	b;
	int				len;

	b = 16;
	n = add;
	len = ft_find_lenght(add);
	while ((16 - len++) > 0)
		write(1, "0", 1);
	while (n >= b)
	{
		write(1, &base[n % b], 1);
		n = n / b;
	}
	write(1, &base[n % b], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_hexa_add((unsigned long)(addr + i), "0123456789abcdef");
		write(1, ": ", 2);
		ft_print_mem((char *)addr + i, "0123456789abcdef");
		ft_putnstr((char *)addr + i, 16);
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
