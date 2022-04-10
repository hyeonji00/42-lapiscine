/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:18:36 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/17 17:15:20 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int *num)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &"0123456789"[num[i]], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

int	is_valid(int *num, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (num[i] == num[idx] || i == idx)
			return (0);
		if (abs(num[i] - num[idx]) == abs(i - idx))
			return (0);
		i++;
	}
	return (1);
}

void	queen(int *num, int idx, int *cnt)
{
	int	i;

	if (idx == 10)
	{
		print_board(num);
		(*cnt)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		num[idx] = i;
		if (is_valid(num, idx))
		{
			queen(num, idx + 1, cnt);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	num[10];
	int	cnt;

	cnt = 0;
	queen(num, 0, &cnt);
	return (cnt);
}
