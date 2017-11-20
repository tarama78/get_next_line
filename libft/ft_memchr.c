/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:04:28 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/07 13:41:56 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
		if (*(unsigned char*)(s++) == (unsigned char)c)
			return ((void*)s - 1);
	return (NULL);
}
