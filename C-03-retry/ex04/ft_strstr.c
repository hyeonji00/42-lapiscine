/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:31:02 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/13 12:23:57 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_str(int i, int j, char *str, char *to_find)
{
	char	*c;

	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
			c = &str[i];
		j = 0;
		while (str[i + j] != '\0' && to_find[j] != '\0')
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (f_strlen(to_find) == j)
			return (c);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	j = 0;
	return (ft_str(i, j, str, to_find));
}
