/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:48:36 by ecloete           #+#    #+#             */
/*   Updated: 2017/06/06 13:05:36 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	length;
	size_t	div;

	length = 0;
	while (length < n && *dest && *(dest++))
		length++;
	div = n - length;
	if (!div)
		return (length + ft_strlen(src));
	while (*src)
	{
		if (div != 1)
		{
			*(dest++) = *src;
			div--;
		}
		src++;
		length++;
	}
	*dest = '\0';
	return (length);
}
