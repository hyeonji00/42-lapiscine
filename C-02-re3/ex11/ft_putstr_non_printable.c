/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:55:17 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/15 13:08:49 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (!(32 <= c && c <= 126))
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*num;
	int		i;
	int		c1;
	int		c2;

	num = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]) == 0)
		{
			c1 = (unsigned char)str[i] / 16;
			c2 = (unsigned char)str[i] % 16;
			write(1, "\\", 1);
			write(1, &num[c1], 1);
			write(1, &num[c2], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
