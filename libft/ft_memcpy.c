/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:51:53 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 19:48:45 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n)
		((char*)dst)[i] = ((char*)src)[i];
	return (dst);
}
