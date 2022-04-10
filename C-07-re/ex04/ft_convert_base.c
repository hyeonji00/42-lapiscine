/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:42:23 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/22 20:35:42 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

int	base_check(char *base, int base_len)
{
	int		i;
	int		j;

	i = 0;
	if (base_len == 0 || base_len == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((9 <= base[i] && base[i] <= 13) || base[i] == ' ')
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

int	is_match(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int base_len)
{
	int		negative;
	int		num;
	int		match;

	negative = 1;
	num = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	match = is_match(*str, base);
	while (match != -1)
	{
		num = num * base_len + match;
		str++;
		match = is_match(*str, base);
	}
	return (negative * num);
}

void	change_base(int n, char *base, int *num, int base_len)
{
	if (n < base_len)
	{
		*num = *num * base_len + n;
		return ;
	}
	else
	{
		change_base(n / base_len, base, num, base_len);
		change_base(n % base_len, base, num, base_len);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	long long	n;
	int			negative;
	int			num;
	int			base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	num = 0;
	negative = 0;
	n = (long long)ft_atoi(str, base, base_len);
	if (base_check(base, base_len) == 0)
		return (0);
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	change_base(n, base, &num, base_len);
	if (negative)
		return (-num);
	return (num);
}
