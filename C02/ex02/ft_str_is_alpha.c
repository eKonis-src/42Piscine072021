/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:08 by nkhedr            #+#    #+#             */
/*   Updated: 2021/06/30 03:58:09 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if (c < 'A' || c > 'z' || (c > 'Z' && c < 'a'))
		return (0);
	return (1);
}

int	ft_str_is_alpha(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!ft_char_is_alpha(*str))
			return (0);
		str++;
	}
	return (1);
}
