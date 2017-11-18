/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: tnicolas <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/11/18 10:20:41 by tnicolas		   #+#	  #+#			  */
/*	 Updated: 2017/11/18 11:39:32 by tnicolas		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <stdio.h>//////////////////////////////////////////////////////////////

static int		ft_create_file(t_file **file, int fd, size_t *nb_file)
{
	*nb_file = 0;
	if (*file != NULL)
		while (file[*nb_file])
			if (file[(*nb_file)++]->fd == fd)
			{
				(*nb_file)--;
				return (SUCCESS);
			}
	if (!(*file = ft_realloc(*file, *nb_file * sizeof(*file),
					(*nb_file + 2) * sizeof(*file))))
		return (ERROR);
	if (!(file[*nb_file] = (t_file*)malloc(sizeof(**file))))
		return (ERROR);
	file[*nb_file]->fd = fd;
	if (!(file[*nb_file]->line_fd = malloc(sizeof(char))))
		return (ERROR);
	file[*nb_file]->line_fd[0] = '\0';
	file[*nb_file + 1] = 0;
	return (SUCCESS);
}

static int		ft_get_line(t_file **file, char **line, size_t nb_file)
{
	int		size_line;
	int		len_file;

	len_file = ft_strlen(file[nb_file]->line_fd);
	size_line = -1;
	while (file[nb_file]->line_fd[++size_line] != '\n' &&
			file[nb_file]->line_fd[size_line] != '\0')
		;
	if (!(*line = malloc(sizeof(**line) * (size_line + 1))))
		return (ERROR);
	ft_strncpy(*line, file[nb_file]->line_fd, size_line);
	(*line)[size_line] = '\0';
		ft_memmove(file[nb_file]->line_fd, file[nb_file]->line_fd + size_line + 1,
				len_file - size_line);
		if (!(file[nb_file]->line_fd = ft_realloc(file[nb_file]->line_fd,
						len_file, len_file - size_line + 1)))
			return (ERROR);
		file[nb_file]->line_fd[len_file - size_line] = '\0';
	return (LINE_READ);
}

static int		ft_read(t_file **file, char **line, size_t nb_file)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	int		ret_read;

	i = 0;
	while (file[nb_file]->line_fd[i] != '\n' && file[nb_file]->line_fd[i])
		i++;
	if (file[nb_file]->line_fd[i] == '\n')
		return (ft_get_line(file, line, nb_file));
	ret_read = 1;
	if ((ret_read = read(file[nb_file]->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		if (!(file[nb_file]->line_fd = ft_realloc(file[nb_file]->line_fd,
				ft_strlen(file[nb_file]->line_fd),
				ft_strlen(file[nb_file]->line_fd) + ret_read)))
			return (ERROR);
		ft_strcat(file[nb_file]->line_fd, buf);
		return (ft_read(file, line, nb_file));
	}
	else if (ret_read == 0 && ft_strlen(file[nb_file]->line_fd) == 0)
		return (END);
	else if (ret_read == 0)
		return (ft_get_line(file, line, nb_file));
	return (ERROR);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file = NULL;
	size_t			nb_file;

	*line = NULL;
	if (ft_create_file(&file, fd, &nb_file) == ERROR)
		return (ERROR);
	return (ft_read(&file, line, nb_file));
//	return(SUCCESS);//
}

////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

void			gnl(int fd)
{
	char	*line;
	int		ret;

	line = NULL;
	printf("----file %d-------\n", fd);
	ret = get_next_line(fd, &line);
	if (ret == ERROR)
		printf("ERROR\n");
	else if (ret == END)
		printf("EOF\n");
	else if (ret == SUCCESS)
	{
		printf("SUCCESS :\n\tline : \"%s\"\n", line);
		free(line);
	}
	else
		printf("\tretour inconnu : %d\n", ret);
	printf("-----------------\n\n");
}

int				main(int ac, char **av)
{
	int			i;

	(void)ac;
	(void)av;
	(void)i;
	int		fd1 = open("f/f3.txt", O_RDONLY);
	int		fd2 = open("f/f4.txt", O_RDONLY);
	int		fd3 = open("f/f5.txt", O_RDONLY);

	gnl(fd1);
	gnl(fd1);
	gnl(fd1);
	gnl(fd1);
	gnl(fd2);
	gnl(fd3);
	gnl(fd3);
	gnl(fd2);
	gnl(fd2);
	gnl(fd2);
	gnl(fd3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (EXIT_SUCCESS);
}
