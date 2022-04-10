/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:37:48 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/08 16:40:39 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	length(int nb)
{
	int		cnt;

	cnt = 1;
	while (nb / 10 > 0)
	{
		nb /= 10;
		cnt ++;
	}
	return (cnt);
}

int	check_negative(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	c[10];
	int		idx;
	int		len;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	nb = check_negative(nb);
	idx = length(nb);
	len = idx;
	while (idx > 0)
	{
		c[idx - 1] = nb % 10 + '0';
		nb = nb / 10;
		idx --;
	}
	while (idx < len)
	{
		write(1, &c[idx], 1);
		idx++;
	}
}
