/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhedr <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:50:58 by nkhedr            #+#    #+#             */
/*   Updated: 2021/07/01 06:29:24 by nkhedr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	rvalue;

	rvalue = 0;
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	if (s1[i] > s2[i])
		rvalue = 1;
	if (s1[i] < s2[i])
		rvalue = -1;
	return (rvalue);
}
