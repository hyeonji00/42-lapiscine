/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fill_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:58:11 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/12 16:22:16 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	_set_x(int order, int side);
int	_set_y(int order, int side);
int	_line_check(int x, int y, int side, char **arr);
int	_check_x(int x, int y, int side, char **arr);
int	_check_y(int x, int y, int side, char **arr);
int	_print_board(int side, char **arr);

int	_fill_board(int order, int side, char **arr)
{
	int	i;
	int	x;
	int	y;

	if (order == side * side + 1)
		return (1);
	i = 1;
	x = _set_x(order, side);
	y = _set_y(order, side);
	while (i <= side)
	{
		arr[x][y] = (i++) + '0';
		if (_line_check(x, y, side, arr))
		{
			if (!_check_x(x, y, side, arr) || !_check_y(x, y, side, arr))
			{
				arr[x][y] = 0;
				return (0);
			}
			if (_fill_board(order + 1, side, arr))
				return (1);
		}
		arr[x][y] = 0;
	}
	return (0);
}

int	_set_x(int order, int side)
{
	if (order % side)
		return (order / side + 1);
	else
		return (order / side);
}

int	_set_y(int order, int side)
{
	if (order % side)
		return (order % side);
	else
		return (side);
}
