//<d0>
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
	int		fd6 = open("f/f6.txt", O_RDONLY); ///empty file
	int		fd7 = open("f/no_newline.txt", O_RDONLY); ///no newline

	gnl(fd7);
	gnl(fd7);
	gnl(fd7);
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
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7);
	return (EXIT_SUCCESS);
}
//</d0>

//<d1>
//#include <string.h>
//#include <fcntl.h>
//#include <stdio.h>
//#include <unistd.h>
//#include "get_next_line.h"
//
//int				main(void)
//{
//	char		*line1;
//	char		*line2;
//	char		*line3;
//	int			fd1;
//	int			fd2;
//	int			fd3;
//	int			ret1;
//	int			ret2;
//	int			ret3;
//	char		*filename1;
//	char		*filename2;
//	int			errors;
//
//	filename1 = "./srcs/gnl/gnl11_1.txt";
//	filename2 = "./srcs/gnl/gnl11_2.txt";
//	fd1 = open(filename1, O_RDONLY);
//	fd2 = open(filename2, O_RDONLY);
//	fd3 = -1;
//	if (fd1 > 2 && fd2 > 2)
//	{
//		errors = 0;
//		line1 = NULL;
//		line2 = NULL;
//		line3 = NULL;
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
//		{
//			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
//		{
//			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
//		{
//			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
//		{
//			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 1 || strcmp(line2, "The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.") != 0)
//		{
//			printf("-> must have returned '1' and read line #1 \"The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.\" from file %s\n", filename2);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 1 || strcmp(line2, "The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. ") != 0)
//		{
//			printf("-> must have returned '1' and read line #2 \"The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. \" from file %s\n", filename2);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 1 || strcmp(line2, "Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. ") != 0)
//		{
//			printf("-> must have returned '1' and read line #3 \"Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. \" from file %s\n", filename2);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 1 || strcmp(line2, "Le Corum cultural and conference centre contains 3 auditoriums. ") != 0)
//		{
//			printf("-> must have returned '1' and read line #4 \"Le Corum cultural and conference centre contains 3 auditoriums. \" from file %s\n", filename2);
//			errors++;
//		}
//
//		ret3 = get_next_line(fd3, &line3);
//		if (ret3 != -1)
//		{
//			printf("-> must have returned '-1' with invalid file descriptor\n");
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "") != 0)
//		{
//			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
//		{
//			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
//		{
//			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
//		{
//			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
//		{
//			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
//		{
//			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 1 || strcmp(line2, "The city is a center for cultural events since there are many students. ") != 0)
//		{
//			printf("-> must have returned '1' and read line #5 \"The city is a center for cultural events since there are many students. \" from file %s\n", filename2);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 1 || strcmp(line2, "Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).") != 0)
//		{
//			printf("-> must have returned '1' and read line #6 \"Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).\" from file %s\n", filename1);
//			errors++;
//		}
//
//		ret1 = get_next_line(fd1, &line1);
//		if (ret1 != 0)
//		{
//			printf("-> must have returned '0' at the end of file %s\n", filename1);
//			errors++;
//		}
//
//		ret2 = get_next_line(fd2, &line2);
//		if (ret2 != 0)
//		{
//			printf("-> must have returned '0' at the end of file %s\n", filename2);
//			errors++;
//		}
//
//		close(fd1);
//		close(fd2);
//		if (errors == 0)
//			printf("OK\n");
//	}
//	else
//		printf("An error occured while opening files %s and/or %s\n", filename1, filename2);
//	return (0);
//}
//</d1>
