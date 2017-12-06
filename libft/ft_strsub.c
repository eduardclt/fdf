/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 12:45:42 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/21 10:54:51 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	substring = (char *)ft_strnew(len);
	i = 0;
	if (substring == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
