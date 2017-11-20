/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:59:21 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/08 14:13:18 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;

	i = -1;
	while (dest[++i])
		;
	j = -1;
	while (src[++j] && n-- > 0)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
