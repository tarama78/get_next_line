/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:00:23 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 15:24:05 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strtrim(const char *s)
{
	char	*ret;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	if (*s == '\0')
		return (ft_strnew(1));
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len++;
	if (!(ret = (char*)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
