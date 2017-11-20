/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:59:49 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/08 21:24:39 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	len++;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && --len > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] && haystack[i] && len - i
				> 0)
		{
			i++;
			if (needle[i] == '\0')
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
