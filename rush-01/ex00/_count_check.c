/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _count_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:49:48 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/12 16:22:09 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_check_x_2(int y, int side, char **arr);
int	_check_y_2(int x, int side, char **arr);

int	_check_x(int x, int y, int side, char **arr)
{
	int		i;
	int		count;
	char	m;

	if (x != side)
		return (1);
	i = 2;
	count = 1;
	m = arr[1][y];
	while (arr[i - 1][y] != side + '0')
	{
		if (m < arr[i][y])
		{
			count++;
			m = arr[i][y];
		}
		i++;
	}
	if (arr[0][y] != count + '0')
		return (0);
	return (_check_x_2(y, side, arr));
}

int	_check_x_2(int y, int side, char **arr)
{
	char	m;
	int		count;
	int		i;

	m = arr[side][y];
	i = side - 1;
	count = 1;
	while (arr[i + 1][y] != side + '0')
	{
		if (m < arr[i][y])
		{
			count++;
			m = arr[i][y];
		}
		i--;
	}
	if (arr[side + 1][y] != count + '0')
		return (0);
	return (1);
}

int	_check_y(int x, int y, int side, char **arr)
{
	int		i;
	int		count;
	char	m;

	if (y != side)
		return (1);
	i = 2;
	count = 1;
	m = arr[x][1];
	while (arr[x][i - 1] != side + '0')
	{
		if (m < arr[x][i])
		{
			count++;
			m = arr[x][i];
		}
		i++;
	}
	if (arr[x][0] != count + '0')
		return (0);
	return (_check_y_2(x, side, arr));
}

int	_check_y_2(int x, int side, char **arr)
{
	int		i;
	int		count;
	char	m;

	m = arr[x][side];
	i = side - 1;
	count = 1;
	while (arr[x][i + 1] != side + '0')
	{
		if (m < arr[x][i])
		{
			count++;
			m = arr[x][i];
		}
		i--;
	}
	if (arr[x][side + 1] != count + '0')
		return (0);
	return (1);
}
