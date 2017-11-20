/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:59:06 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 15:22:37 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strmap(const char *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		;
	if (!(ret = (char*)malloc(sizeof(*ret) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = f(s[i]);
	ret[i] = '\0';
	return (ret);
}
