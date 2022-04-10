/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:31:20 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/24 12:33:27 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_map(char *av, int fd)
{
	int		i;
	t_map	*map;
	char	*buf;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == 0)
		return (0);
	i = 0;
	map->x = 0;
	map->y = 0;
	while (av[i] != '\n')
	{
		read(fd, &buf, 1);
		if (is_printable(*buf))
			map->size = ft_atoi(buf);
	}
	while (av[i] != '\0')
	{
	}
	if (map->x != map->y)
		return (0);
	return (1);
}

char	*read_file(void)
{
	char	*buf;
	int		err;

	err = read(0, &buf, 1);
	while (buf != 0)
	{
		if (err == -1)
		{
			print_error();
			return (0);
		}
		err = read(0, &buf, 1);
	}
	return (buf);
}

char	*read_input(void)
{
	char	*buf;
	int		err;

	err = read(0, &buf, 1);
	while (buf != 0)
	{
		if (err == -1)
		{
			print_error();
			return (0);
		}
		err = read(0, &buf, 1);
	}
	return (buf);
}

void	read_map(int fd)
{
	char	*map;

	if (fd == 0)
		map = read_input();
	else
		map = read_file();
	if (map == 0)
	{
		print_error();
		return ;
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	fd;

	i = 1;
	if (ac != 1)
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
			{
				print_error();
				return (0);
			}
			read_map(fd);
			i++;
		}
	}
	else
		read_map(0);
}
