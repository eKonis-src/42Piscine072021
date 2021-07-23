/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:19:07 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/12 20:44:58 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(long i, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_get_base_nb(char c, char *base)
{
	int	j;

	j = -1;
	while (base[++j])
		if (base[j] == c)
			return (j);
	return (-1);
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
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| base[i] <= 31 )
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

int	ft_atoi_base(char *str, char *base)
{
	int		mult;
	long	i;

	i = 0;
	mult = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mult *= -1;
		str++;
	}
	while (ft_get_base_nb(*str, base) != -1)
	{
		i *= ft_strlen(base);
		i += ft_get_base_nb(*str, base);
		str++;
	}
	return ((int) i * mult);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;

	i = 0;
	if (ft_check_base(base_from) && ft_check_base(base_to))
	{
		return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
	}
	return (NULL);
}
