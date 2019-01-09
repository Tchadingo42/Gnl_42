/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:04:30 by chbelan           #+#    #+#             */
/*   Updated: 2019/01/09 16:58:01 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int			main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (84);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
*/

int			main(int argc , char **argv)
{
	char	*line;
	int		fd;
	int		fd2;
	int 	ret;

	ret = 0;
	if (argc < 2)
		return (1);
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY, 0);
		fd2 = open(argv[2], O_RDONLY, 0);
		while (get_next_line(fd, &line) > 0)
		{
			printf("[%d]%s\n", ret, line);
			free(line);
			ret++;
		}
		while (get_next_line(fd2, &line) > 0)
		{
			printf("[%d]%s\n", ret, line);
			free(line);
			ret++;
		}
		free(line);
		close(fd);
		close(fd2);
	}
	return (0);
}
