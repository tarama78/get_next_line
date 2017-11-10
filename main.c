/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:58:58 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/10 15:29:47 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include "get_next_line.h"

void			gnl(int fd)
{
	char		*line;
	
	printf("line (fd = %d):\n", fd);
	if (get_next_line(fd, &line) == LINE_READ)
	{
		printf("\t\"%s\"\n\n", line);
		free(line);
	}
	else
		printf("\tNOLINE\n");
}

int				main(int ac, char **av)
{
	int			i;
	int			fd1 = open("file1.txt", O_RDONLY);
	// file2.txt : OK, a (empty file) : segfault
	int			fd2 = open("a", O_RDONLY);
	int			fd3 = open("file3.txt", O_RDONLY);
	(void)ac;
	(void)av;
	(void)i;
	gnl(fd1);
	gnl(fd2);
	gnl(fd1);
	gnl(fd3);
	gnl(fd2);
	gnl(fd3);
	gnl(fd3);
	gnl(fd3);
	gnl(fd1);
	return (0);
}
/*
gcc -Wall -Wextra -Werror -o get_next_line.o -c get_next_line.c && gcc -Wall -Wextra -Werror -o main.o -c main.c && gcc -o a.out main.o get_next_line.o && ./a.out && rm a.out
*/
