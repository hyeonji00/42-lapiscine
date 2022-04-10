/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:21:53 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/14 16:27:47 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	change_base(long long n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < base_len)
	{
		write(1, &base[n], 1);
		return ;
	}
	else
	{
		change_base(n / base_len, base);
		change_base(n % base_len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	n;

	n = (long long)nbr;
	if (base_check(base) == 0)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	change_base(n, base);
}
