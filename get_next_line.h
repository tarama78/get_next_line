/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:56:02 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/22 13:56:09 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
