/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:58:52 by ecloete           #+#    #+#             */
/*   Updated: 2017/06/06 12:58:55 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*s2;
	char	*s1;

	i = 0;
	s1 = (char *)str1;
	s2 = (char *)str2;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
