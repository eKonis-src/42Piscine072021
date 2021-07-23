/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:38:12 by nkhedr            #+#    #+#             */
/*   Updated: 2021/06/30 03:58:50 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!ft_char_is_numeric(*str))
			return (0);
		str++;
	}
	return (1);
}
