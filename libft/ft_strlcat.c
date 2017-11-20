/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:38:57 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/08 14:19:53 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		size2;
	int		lendst;

	i = -1;
	while (dst[++i])
		;
	j = -1;
	size2 = size;
	lendst = ft_strlen(dst);
	if (size <= (size_t)lendst)
		return (size + ft_strlen(src));
	if (size == (size_t)lendst + 1)
		return (size + ft_strlen(src) - 1);
	while (src[++j] && size2-- - lendst - 1 > 0)
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (lendst + ft_strlen(src));
}
