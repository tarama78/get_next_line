#include "get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <stdio.h>//dd

//<d1>
//void ft_printstruct(t_file *f)
//{
//	while (f != NULL)
//	{
//		printf("=====\n\tfd : %d\n\tstr : \"%s\"\n\tnext : %p\n=====\n", f->fd, f->s, f->next);
//		f = f->next;
//	}
//	int		n;
//
//	n = -1;
//	while ((t_file*)ft_lstget((t_list*)f, ++n))
//	{
//		printf("===== %d\n\tfd: %d\n\tstr: %s\n\tnext: %p\n=====\n", n,
//				((t_file*)ft_lstget((t_list*)f, n))->fd,
//				((t_file*)ft_lstget((t_list*)f, n))->s,
//				((t_file*)ft_lstget((t_list*)f, n))->next);
//	}
//}
//</d1>

static int		ft_fruit(t_file **f, size_t n)
{
	t_file		*to_del;

	to_del = ((t_file*)ft_lstget((t_list*)*f, n));
	if (n > 0)
	{
		((t_file*)ft_lstget((t_list*)*f, n - 1))->next =
			((t_file*)ft_lstget((t_list*)*f, n + 1));
	}
	else
	{
		to_del = *f;
		*f = (*f)->next;
	}
	free(to_del->s);
	free(to_del);
	return (SUCCESS);
}

static int		ft_create_struct(t_file **f, int fd, size_t *n)
{
	t_file		*new;

	*n = 0;
	while (((t_file*)ft_lstget((t_list*)*f, *n)))
	{
		if (((t_file*)ft_lstget((t_list*)*f, *n))->fd == fd)
			return (SUCCESS);
		(*n)++;
	}
	*n = 0;
	if (!(new = malloc(sizeof(t_file))))
		return (ERROR);
	new->fd = fd;
	if (!(new->s = malloc(sizeof(char))))
		return (ERROR);
	new->s[0] = '\0';
	new->next = *f;
	*f = new;
	return (SUCCESS);
}

static int		ft_get_line(t_file *tmp, char **line, size_t n)
{
	size_t	size_line;
	size_t	len_file;

	(void)n;//dd
	len_file = ft_strlen(tmp->s);
	size_line = 0;
	while (tmp->s[size_line] != '\n' && tmp->s[size_line] != '\0')
		size_line++;
//	printf("ft_get_line :\n\t%zu\n\t%zu\n\ttmp->s(before) : |%s|\n", len_file, size_line, tmp->s);//dd
	if (!(*line = malloc(sizeof(**line) * (size_line + 1))))
		return (ERROR);
	ft_strncpy(*line, tmp->s, size_line);
	(*line)[size_line] = '\0';
	ft_memmove(tmp->s, tmp->s + size_line + 1, len_file - size_line);
	if (!(tmp->s = ft_realloc(tmp->s, len_file + 1, len_file - size_line + 1)))
		return (ERROR);
	tmp->s[len_file - size_line - 1] = '\0';
//	printf("\ttmp->s(after) : |%s|\n", tmp->s);//dd
	return (LINE_READ);
}

static int		ft_read(t_file *f, char **line, size_t n)
{
	int		i;
	t_file	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret_read;

	i = 0;
	tmp = ((t_file*)ft_lstget((t_list*)f, n));
	while (tmp->s[i] != '\n' && tmp->s[i])
		i++;
	if (tmp->s[i] == '\n')
		return (ft_get_line(tmp, line, n));
	ret_read = 1;
	if ((ret_read = read(tmp->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		if (!(tmp->s = ft_realloc(tmp->s, ft_strlen(tmp->s) + 1,
						ft_strlen(tmp->s) + ret_read + 1)))
			return (ERROR);
		ft_strncat(tmp->s, buf, ret_read);
		return (ft_read(f, line, n));
	}
	else if (ret_read == 0 && ft_strlen(tmp->s) == 0)
		return (END);
	else if (ret_read == 0)
		return (ft_get_line(tmp, line, n));
	return (ERROR);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f = NULL;
	size_t			n;
	int				ret;

	*line = NULL;
	ret = 0;
	if (ft_create_struct(&f, fd, &n) == ERROR)
		return (ERROR);
//	printf("n : %zu\n", n);//dd
	ret = ft_read(f, line, n);
	if (ret == END)
		if (ft_fruit(&f, n) == ERROR)
			return (ERROR);
//	ft_printstruct(f);//dd
	return (ret);
}

//<d0>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <limits.h>
//#include <string.h>
//#include <ctype.h>
//#include <fcntl.h>
//
//void			gnl(int fd)
//{
//	char	*line;
//	int		ret;
//
//	line = NULL;
//	printf("----file %d-------\n", fd);
//	ret = get_next_line(fd, &line);
//	if (ret == ERROR)
//		printf("ERROR\n");
//	else if (ret == END)
//		printf("EOF\n");
//	else if (ret == SUCCESS)
//	{
//		printf("SUCCESS :\n\tline : \"%s\"\n", line);
//		free(line);
//	}
//	else
//		printf("\tretour inconnu : %d\n", ret);
//	printf("-----------------\n\n");
//}
//
//int				main(int ac, char **av)
//{
//	int			i;
//
//	(void)ac;
//	(void)av;
//	(void)i;
//	int		fd3 = open("f/f3.txt", O_RDONLY);
//	int		fd4 = open("f/f4.txt", O_RDONLY);
//	int		fd5 = open("f/f5.txt", O_RDONLY);
//	int		fd6 = open("f/f6.txt", O_RDONLY);
//
//	gnl(fd3);
//	gnl(fd4);
//	gnl(fd3);
//	gnl(fd4);
//	gnl(fd5);
//	gnl(fd5);
//	gnl(fd3);
//	gnl(fd3);
//	gnl(fd4);
//	gnl(fd5);
//	gnl(fd5);
//	gnl(fd6);
//	close(fd3);
//	close(fd4);
//	close(fd5);
//	close(fd6);
//	return (EXIT_SUCCESS);
//}
//</d0>
