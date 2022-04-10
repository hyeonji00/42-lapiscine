/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:07 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/23 14:38:15 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int num1, int num2);
int	sub(int num1, int num2);
int	div(int num1, int num2);
int	mul(int num1, int num2);
int	mod(int num1, int num2);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		write(1, &str[i++], 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	zero_div_mod(char op, int num2)
{
	if (op == '/' && num2 == 0)
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	if (op == '%' && num2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

void	do_op(int num1, char op, int num2)
{
	int	(*cal[5])(int, int);
	int	result;

	result = 0;
	cal[0] = &add;
	cal[1] = &sub;
	cal[2] = &div;
	cal[3] = &mul;
	cal[4] = &mod;
	if (zero_div_mod(op, num2))
		return ;
	if (op == '+')
		result = cal[0](num1, num2);
	else if (op == '-')
		result = cal[1](num1, num2);
	else if (op == '/')
		result = cal[2](num1, num2);
	else if (op == '*')
		result = cal[3](num1, num2);
	else if (op == '%')
		result = cal[4](num1, num2);
	else
		return ;
	ft_putnbr((long long)result);
}
