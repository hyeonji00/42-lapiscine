/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:43:09 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/23 18:23:06 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_check(char *base, int base_len);
int		ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	cnt_arr(long long nbr, char *base_to)
{
	int	cnt;

	cnt = 0;
	if (nbr == 0)
		cnt = 1;
	while (nbr != 0)
	{
		cnt++;
		nbr /= ft_strlen(base_to);
	}
	return (cnt);
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	int		cnt;
	char	*arr;
	int		sign;

	sign = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
	}
	cnt = cnt_arr(nbr, base);
	if (sign == 1)
		cnt++;
	arr = (char *)malloc(sizeof(char) * (cnt + 1));
	if (arr == 0)
		return (0);
	arr[cnt] = 0;
	if (sign == 1)
		arr[0] = '-';
	while (cnt-- > sign)
	{
		arr[cnt] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;

	if (base_check(base_from, ft_strlen(base_from)) == 0
		|| base_check(base_to, ft_strlen(base_to)) == 0)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(num, base_to));
}
