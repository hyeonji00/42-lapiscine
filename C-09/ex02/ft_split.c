/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:41:12 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/22 12:43:55 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_cnt(char *str, char *charset)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(charset, str[i]))
		{
			while (str[i] && !is_charset(charset, str[i]))
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	arr = (char **)malloc(sizeof(char *) * (check_cnt(str, charset) + 1));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = i;
		if (!is_charset(charset, str[i]))
		{
			while (str[i] && !is_charset(charset, str[i]))
				i++;
			arr[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(arr[k++], str + j, i - j);
		}
		else
			i++;
	}
	arr[k] = 0;
	return (arr);
}
