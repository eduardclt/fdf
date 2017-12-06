/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:22:46 by ecloete           #+#    #+#             */
/*   Updated: 2017/06/10 11:36:56 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_setlen(const char *s, size_t *start)
{
	size_t end;

	end = 0;
	while ((s[*start] == '\n' || s[*start] == ' ' || s[*start] == '\t')
			&& s[*start] != '\0')
		*start += 1;
	end = ft_strlen(s);
	while (end > 0 && (s[end] == '\n' || s[end] == ' ' || s[end] == '\t'
			|| s[end] == '\0'))
		end--;
	if (end != 0)
		end++;
	if (end < *start)
	{
		*start = 0;
		end = 0;
	}
	return (end - *start);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	str = NULL;
	if (s != NULL)
	{
		len = ft_setlen(s, &i);
		str = ft_strnew(len);
		if (str != NULL)
		{
			ft_memcpy((void *)(str), (void *)(s + i), len);
			str[len + 1] = '\0';
		}
	}
	return (str);
}
