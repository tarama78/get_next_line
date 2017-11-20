/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:58:25 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 17:07:02 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)malloc(sizeof(*ret) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
