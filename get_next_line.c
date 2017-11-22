#include "get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

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

static int		ft_get_line(t_file *tmp, char **line)
{
	size_t	size_line;
	size_t	len_file;

	len_file = ft_strlen(tmp->s);
	size_line = 0;
	while (tmp->s[size_line] != '\n' && tmp->s[size_line] != '\r' &&
			tmp->s[size_line] != '\0')
		size_line++;
	if (!(*line = malloc(sizeof(**line) * (size_line + 1))))
		return (ERROR);
	ft_strncpy(*line, tmp->s, size_line);
	(*line)[size_line] = '\0';
	ft_memmove(tmp->s, tmp->s + size_line + 1, len_file - size_line);
	if (!(tmp->s = ft_realloc(tmp->s, len_file + 1, len_file - size_line + 1)))
		return (ERROR);
	tmp->s[len_file - size_line] = '\0';
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
	while (tmp->s[i] != '\n' && tmp->s[i] != '\r' && tmp->s[i])
		i++;
	if (tmp->s[i] == '\n' || tmp->s[i] == '\r')
		return (ft_get_line(tmp, line));
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
		return (ft_get_line(tmp, line));
	return (ERROR);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f = NULL;
	size_t			n;
	int				ret;

	if (fd < 0 || line == NULL)
		return (ERROR);
	*line = NULL;
	ret = 0;
	if (ft_create_struct(&f, fd, &n) == ERROR)
		return (ERROR);
	ret = ft_read(f, line, n);
	if (ret == END)
		if (ft_fruit(&f, n) == ERROR)
			return (ERROR);
	return (ret);
}
