/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:00:16 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 15:07:44 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		i;

	if (s == NULL)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	s += start;
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
