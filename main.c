/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:58:58 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 20:31:39 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "get_next_line.h"

int				main(int ac, char **av)
{
	int			i;
	int			fd1 = 1, fd2 = 2, fd3 = 3;
	char		*line;
	(void)ac;
	(void)av;
	(void)i;
	get_next_line(fd1, &line);
	get_next_line(fd2, &line);
	get_next_line(fd3, &line);
	get_next_line(fd1, &line);
	get_next_line(fd2, &line);
	get_next_line(fd3, &line);
	get_next_line(fd1, &line);
	get_next_line(fd3, &line);
	get_next_line(fd3, &line);
	return (0);
}
