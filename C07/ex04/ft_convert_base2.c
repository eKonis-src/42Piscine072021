/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:21:42 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/12 20:30:32 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

long	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_get_lenght(long i, long b)
{
	int	radix;

	radix = 1;
	while (i >= ft_recursive_power(b, radix))
		radix += 1;
	return (radix);
}

void	ft_set_values(int *offset, char *str, long *i)
{
	*offset = 1;
	str[0] = '-';
	*i = -(*i);
}

char	*ft_itoa_base(long i, char *base)
{
	int		leni;
	int		offset;
	char	*str;

	offset = 0;
	if (i < 0)
		leni = ft_get_lenght(-i, ft_strlen(base)) + 1;
	else
		leni = ft_get_lenght(i, ft_strlen(base));
	str = malloc(sizeof(char) * (leni + 1));
	if (i < 0)
		ft_set_values(&offset, str, &i);
	if (leni == 0)
		return (NULL);
	str[leni] = '\0';
	leni--;
	while (leni >= offset)
	{
		str[leni] = base[i % ft_strlen(base)];
		i = i / ft_strlen(base);
		leni--;
	}
	return (str);
}
