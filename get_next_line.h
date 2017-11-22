#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024
# define END 0
# define LINE_READ 1
# define SUCCESS 1
# define ERROR -1

typedef struct			s_file
{
	int					fd;
	char				*s;
	struct s_file		*next;
}						t_file;

int						get_next_line(const int fd, char **line);

#endif
