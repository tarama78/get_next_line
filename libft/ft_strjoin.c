/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:45:47 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 17:07:01 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		i;
	int		lens1;
	int		lens2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(*ret) * (lens1 + lens2 + 1))))
		return (NULL);
	i = -1;
	while (++i < lens1)
		ret[i] = s1[i];
	i--;
	while (++i < lens1 + lens2)
		ret[i] = s2[i - lens1];
	ret[i] = '\0';
	return (ret);
}
