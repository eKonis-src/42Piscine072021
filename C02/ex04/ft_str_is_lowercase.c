/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:36:53 by nkhedr            #+#    #+#             */
/*   Updated: 2021/06/30 03:59:20 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	ft_str_is_lowercase(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!ft_char_is_lowercase(*str))
			return (0);
		str++;
	}
	return (1);
}
