/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:47:08 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/09 20:25:42 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64
# define FD 0
# define LINE 1

typedef struct	s_file
{
	int			fd;
	int			line;
	char		*content;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
