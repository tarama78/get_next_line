/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:47:12 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 15:00:53 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *nptr)
{
	int		ret;
	int		neg;

	while (!(ret = 0) && (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' ||
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		++nptr;
	neg = (*nptr == '-') ? -1 : 1;
	nptr = (*nptr == '-' || *nptr == '+') ? nptr : nptr - 1;
	while (*(++nptr) >= '0' && *nptr <= '9')
		ret = ret * 10 + *nptr - '0';
	return (ret * neg);
}
