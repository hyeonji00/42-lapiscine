/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:46:29 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/16 17:25:42 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		_fill_board(int order, int side, char **arr);
void	_print_board(int side, char **arr);
void	board_main(int side, char **arr, char *argv[]);
int		_line_check(int x, int y, int side, char **arr);
int		_count_check_x(int y, int side, char **arr);
int		_count_check_y(int x, int side, char **arr);
int		ft_strlen(char *arr);
int		_check_argv(char *argv);

int	main(int argc, char *argv[])
{
	int		i;
	int		side;
	char	**arr;

	i = 0;
	if (argc != 2 || (ft_strlen(argv[1]) + 1) % 8 != 0 || !_check_argv(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	side = (ft_strlen(argv[1]) + 1) / 8;
	if (side == 1 && argv[1][0] + argv[1][2] + argv[1][4] + argv[1][6] != 196)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	arr = (char **)malloc(sizeof(char *) * (side + 2));
	while (i < side + 2)
		arr[i++] = (char *)malloc(sizeof(char) * (side + 2));
	board_main(side, arr, argv);
	i = 0;
	while (i < side + 2)
		free(arr[i++]);
	free(arr);
	return (0);
}

void	board_main(int side, char **arr, char *argv[])
{
	int	i;

	i = 1;
	while (i < side + 1)
	{
		arr[0][i] = argv[1][2 * i - 2];
		arr[side + 1][i] = argv[1][2 * (side + i - 1)];
		arr[i][0] = argv[1][2 * (side * 2 + i - 1)];
		arr[i][side + 1] = argv[1][2 * (side * 3 + i - 1)];
		i++;
	}
	i = 1;
	while (i <= side)
	{
		arr[1][1] = i + '0';
		if (_fill_board(2, side, arr))
		{
			_print_board(side, arr);
			return ;
		}
		i++;
	}
	write(1, "Error\n", 6);
	return ;
}

int	_line_check(int x, int y, int side, char **arr)
{
	int		i;

	i = 1;
	while (i <= side)
	{
		if (arr[x][i] == arr[x][y] && i != y)
			return (0);
		if (arr[i][y] == arr[x][y] && i != x)
			return (0);
		i++;
	}
	return (1);
}

void	_print_board(int side, char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i <= side)
	{
		j = 1;
		while (j <= side)
		{
			write(1, &arr[i][j], 1);
			if (j != side)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	_check_argv(char *argv)
{
	int	count_1;

	count_1 = 0;
	while (1)
	{
		if (*argv < '1' || *argv > '9')
			return (0);
		if (*argv == '1')
			count_1++;
		if (count_1 > 4)
			return (0);
		argv++;
		if (*argv == '\0')
			return (1);
		if (*argv != ' ')
			return (0);
		argv++;
	}
}
