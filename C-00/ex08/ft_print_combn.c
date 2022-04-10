/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:10:07 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/08 16:43:01 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_func(char *num, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, &num[i], 1);
		i++;
	}
}

void	find_num(char *num, int n)
{
	int		i;

	i = n - 1;
	write(1, ", ", 2);
	if (num[i] == '9')
	{
		while (num[i] == '9' - (n - 1 - i))
		{
			i--;
		}
		num[i]++;
		while (i < n - 1)
		{
			num[i + 1] = num[i] + 1;
			i++;
		}
	}
	else
	{
		num[i]++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	num[10];

	i = 0;
	while (i < n)
	{
		num[i] = i + '0';
		i++;
	}
	print_func(num, n);
	while (1)
	{
		if (num[0] == 10 - n + '0' && num[n - 1] == '9')
		{
			break ;
		}
		find_num(num, n);
		print_func(num, n);
	}
}
