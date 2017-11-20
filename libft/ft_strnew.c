/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:59:44 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 10:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strnew(size_t size)
{
	char	*ret;

	if (!(ret = (char*)malloc(size + 1)))
		return (NULL);
	while (size > 0)
		ret[size--] = 0;
	ret[0] = 0;
	return (ret);
}
