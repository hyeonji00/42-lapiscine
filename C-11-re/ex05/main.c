/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:47 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/23 14:31:18 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	do_op(int num1, char op, int num2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	is_valid(char *str)
{
	if (ft_strcmp(str, "+") == 0)
		return (1);
	if (ft_strcmp(str, "-") == 0)
		return (1);
	if (ft_strcmp(str, "/") == 0)
		return (1);
	if (ft_strcmp(str, "*") == 0)
		return (1);
	if (ft_strcmp(str, "%") == 0)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		negative;
	int		num;

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
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (negative * num);
}

int	main(int ac, char *av[])
{
	int		num1;
	int		num2;
	char	*op;

	if (ac == 4)
	{
		if (is_valid(av[2]))
		{
			num1 = ft_atoi(av[1]);
			op = av[2];
			num2 = ft_atoi(av[3]);
			do_op(num1, op[0], num2);
		}
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return (0);
}
