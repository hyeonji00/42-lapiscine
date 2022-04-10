/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:29:24 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/14 14:20:00 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	is_alpha_num(char c)
{
	if (is_upper(c) || is_lower(c))
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	if (is_lower(str[0]) == 1)
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (is_lower(str[i]))
			if (is_alpha_num(str[i - 1]) == 0)
				str[i] -= 32;
		if (is_upper(str[i]))
			if (is_alpha_num(str[i - 1]))
				str[i] += 32;
		i++;
	}
	return (str);
}
