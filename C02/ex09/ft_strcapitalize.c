/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:34:48 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/01 12:26:51 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lowcase(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	ft_is_alphanum(char c)
{
	if (! ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9' )))
		return (0);
	return (1);
}

int	ft_is_num(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	f_letter;
	int	i;

	f_letter = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_is_alphanum(str[i]))
			f_letter = 1;
		else
		{
			if (!ft_is_num(str[i]) && !ft_is_lowcase(str[i]))
				str[i] += 32;
			if (ft_is_lowcase(str[i]) && f_letter)
				str[i] -= 32;
			f_letter = 0;
		}
		i++;
	}
	return (str);
}
