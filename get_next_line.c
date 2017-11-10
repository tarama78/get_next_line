/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:53:40 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 20:29:37 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>//////////////////////////////////////////////////////////////
#include <string.h>/////////////////////////////////////////////////////////////

static size_t	ft_get_fd_content(int fd, char **buf)
{
	char		tmp[BUFF_SIZE + 1];
	ssize_t		ret_read;
	size_t		size_file;
	char		*ptr_tmp;

	*buf = 0;
	size_file = 0;
	while ((ret_read = read(fd, tmp, sizeof(tmp) - 1)) > 0)
	{
		tmp[ret_read] = '\0';
		size_file += ret_read;
		ptr_tmp = *buf;
		if (!(*buf = malloc(size_file + 1)))
			return (0);
		(*buf)[0] = '\0';
		if (ptr_tmp == NULL)
			strncat(*buf, tmp, size_file);////////////////ft_strncat
		else
		{
			strncat(*buf, ptr_tmp, size_file);////////ft_strncat
			strncat(*buf, tmp, size_file - strlen(*buf));//ft_strlen ft_strncaf
			free(ptr_tmp);
		}
	}
	return (size_file);
}

static int		ft_get_nb_files(t_file *files, int fd, int *new_file)
{
	int		nb_files;
	int		i;

	nb_files = 0;
	while (files[nb_files].fd != 0)
		nb_files++;
	i = -1;
	while (++i < nb_files)
	{
		if (files[i].fd == fd)
		{
			*new_file = 0;
			break;
		}
	}
	return (nb_files + *new_file);
}

static void		ft_create_files(t_file **files, int nb_files, int new_fd)
{
	t_file	*files2;
	int		i;

	if (!(files2 = (t_file*)malloc(sizeof(*files2) * (nb_files + 1))))
		return ;
	i = -1;
	while (++i < nb_files)
	{
		if (i < nb_files - 1 && (*files)[i].fd != 0)
		{
			files2[i].fd = (*files)[i].fd;
			files2[i].line = (*files)[i].line;
			files2[i].content = (*files)[i].content;
		}
		else
		{
			files2[i].fd = new_fd;
			files2[i].line = 0;
			ft_get_fd_content(new_fd, &(files2[i].content));
		}
	}
	free(*files);
	files2[i].fd = 0;
	*files = files2;
}

static void		ft_readline(t_file **files, int fd, char **line)
{
	int		f;
	char	*buf;

	(void)line;
	f = -1;
	while ((*files)[++f].fd != fd)
		;
	if (!(buf = malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return ;

	free(buf);
	(*files)[f].line++;
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*files = 0;
	int				nb_files;
	int				new_file;
	int				i;

	(void)line;
	(void)i;
	new_file = 1;
	if (files == 0)
		nb_files = 1;
	else
		nb_files = ft_get_nb_files(files, fd, &new_file);
	if (new_file == 1)
		ft_create_files(&files, nb_files, fd);
	ft_readline(&files, fd, line);

	printf("get_next_line : (fd = %d)\n", fd);
	i = -1;
	while (++i < nb_files)
	{
		printf("\tfd : %d\tline : %d\n", files[i].fd, files[i].line);
	}
	return (0);
}
