/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:47:39 by ecloete           #+#    #+#             */
/*   Updated: 2017/05/23 11:11:29 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;

	result = (char *)malloc(ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	result = ft_strcpy(result, str);
	return (result);
}
