/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:41:40 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/08 16:38:35 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	print_char(int num)
{
	char	c1;
	char	c2;

	c1 = '0';
	c2 = '0';
	if (num >= 10)
	{
		c1 = num / 10 + '0';
	}
	if (num != 0)
	{
		c2 = num % 10 + '0';
	}
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_print_comb2(void)
{
	int		num1;
	int		num2;

	num1 = 0;
	while (num1 < 99)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			if (num1 < num2)
			{
				print_char(num1);
				write(1, " ", 1);
				print_char(num2);
				if (!(num1 == 98 && num2 == 99))
				{
					write(1, ", ", 2);
				}
			}
			num2 ++;
		}
		num1 ++;
	}
}
