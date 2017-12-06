/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:29:44 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/21 11:18:35 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	if (*lit == '\0')
		return ((char*)big);
	if (!len)
		return (NULL);
	while (*big != '\0' && len >= ft_strlen(lit))
	{
		if (ft_strncmp(big, lit, ft_strlen(lit)) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
