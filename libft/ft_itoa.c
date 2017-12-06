/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:13:03 by ecloete           #+#    #+#             */
/*   Updated: 2017/06/09 13:19:43 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*create_str(int *len, int i)
{
	char	*str;

	if (i < 0)
	{
		str = ft_strnew(++(*len));
		if (str != NULL)
			str[0] = '-';
		else
			return (NULL);
	}
	else
		str = ft_strnew(*len);
	return (str);
}

char		*ft_itoa(int i)
{
	int		len;
	char	*str;

	len = ft_num_len(i);
	str = create_str(&len, i);
	if (str != NULL)
	{
		len--;
		while (str[len] != '-' && len >= 0)
		{
			str[len] = '0' + ft_tonegative(i % 10);
			i /= 10;
			len--;
		}
	}
	return (str);
}
