#include "get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <stdio.h>///

void ft_printstruct(t_file **file)
{
	int i = -1;
	while (file[++i] != 0)
	{
		printf("\tfd : %d\n\t\tline : %s\n", file[i]->fd, file[i]->line_fd);
	}
}

static int		ft_fruit(t_file **file, size_t *nb_file)
{
	free(file[*nb_file]->line_fd);
	free(file[*nb_file]);
	while (file[++(*nb_file)])
		file[*nb_file - 1] = file[*nb_file];
	if (!(*file = (t_file*)ft_realloc(*file, (*nb_file + 1) * sizeof(t_file*),
					(*nb_file - 0) * sizeof(t_file*))))///
		return (ERROR);
	file[*nb_file - 1] = 0;
//	printf("pointeur (ft_fruit) : %p\n", file[0]);
//	printf("nb_file(ft_fruit) : %zu\n", *nb_file);
	return (SUCCESS);
}

static int		ft_create_struct(t_file **file, int fd, size_t *nb_file)
{
	*nb_file = 0;
	if (*file != NULL)
		while (file[*nb_file])
			if (file[(*nb_file)++]->fd == fd)
			{
				(*nb_file)--;
				return (SUCCESS);
			}
	if (!(*file = (t_file*)ft_realloc(*file, *nb_file * sizeof(t_file*),
					(*nb_file + 2) * sizeof(t_file*))))//////////////////////////
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
	size_t	size_line;
	size_t	len_file;

	len_file = ft_strlen(file[nb_file]->line_fd);
	size_line = 0;
	while (file[nb_file]->line_fd[size_line] != '\n' &&
			file[nb_file]->line_fd[size_line] != '\0')
		size_line++;
	if (!(*line = malloc(sizeof(**line) * (size_line + 1))))
		return (ERROR);
	ft_strncpy(*line, file[nb_file]->line_fd, size_line);
	(*line)[size_line] = '\0';
	ft_memmove(file[nb_file]->line_fd, file[nb_file]->line_fd + size_line + 1,
			len_file - size_line);
	if (!(file[nb_file]->line_fd = ft_realloc(file[nb_file]->line_fd,
					len_file, len_file - size_line)))
		return (ERROR);
	file[nb_file]->line_fd[len_file - size_line - 1] = '\0';
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
						ft_strlen(file[nb_file]->line_fd) + 1,
						ft_strlen(file[nb_file]->line_fd) + ret_read + 1)))
			return (ERROR);
		ft_strncat(file[nb_file]->line_fd, buf, ret_read);
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
	int				ret;

	*line = NULL;
	nb_file = 0;
	if (ft_create_struct(&file, fd, &nb_file) == ERROR)
		return (ERROR);
	ret = ft_read(&file, line, nb_file);
//	ft_printstruct(&file);
	if (ret == END)
		if (ft_fruit(&file, &nb_file) == ERROR)
			return (ERROR);
//	ft_printstruct(&file);
	return (ret);
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
	int		fd3 = open("f/f3.txt", O_RDONLY);
	int		fd4 = open("f/f4.txt", O_RDONLY);
	int		fd5 = open("f/f5.txt", O_RDONLY);
	int		fd6 = open("f/f6.txt", O_RDONLY);

	gnl(fd6);
	gnl(fd6);
	gnl(fd3);
	gnl(fd3);
	gnl(fd3);
	gnl(fd4);
	gnl(fd5);
	gnl(fd5);
	gnl(fd4);
	gnl(fd3);
	gnl(fd4);
	gnl(fd4);
	gnl(fd5);
	close(fd3);
	close(fd4);
	close(fd5);
	return (EXIT_SUCCESS);
}
