/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 09:34:04 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/20 09:34:06 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*newlist;

	new = *alst;
	while (new)
	{
		newlist = new->next;
		del(new->content, new->content_size);
		free(new);
		new = newlist;
	}
	*alst = NULL;
}
