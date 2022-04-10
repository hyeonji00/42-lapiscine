/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:40:07 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/22 20:24:50 by hyeonjik         ###   ########.fr       */
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

int	all_strlen(char **strs, int size)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		cnt += ft_strlen(strs[i]);
		i++;
	}
	return (cnt);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*arr;

	if (size == 0)
	{
		arr = malloc(1);
		return (arr);
	}
	len = all_strlen(strs, size) + ((size - 1) * ft_strlen(sep));
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	arr[0] = 0;
	i = 0;
	while (i < size)
	{
		arr = ft_strcat(arr, strs[i]);
		if (i < size - 1)
			arr = ft_strcat(arr, sep);
		i++;
	}
	arr[len] = '\0';
	return (arr);
}
