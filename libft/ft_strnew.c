/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:54:55 by ecloete           #+#    #+#             */
/*   Updated: 2017/06/09 12:49:11 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)ft_memalloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', (size + 1));
	return (ptr);
}
