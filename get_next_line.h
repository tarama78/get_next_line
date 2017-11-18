/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:20:18 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/18 14:12:45 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64
# define END 0
# define LINE_READ 1
# define SUCCESS 1
# define ERROR -1

typedef struct			s_file
{
	int					fd;
	char				*line_fd;
}						t_file;

int						get_next_line(const int fd, char **line);

#endif
