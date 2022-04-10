/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:38:22 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/22 20:10:56 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			*arr;
	int			i;
	long long	num;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	num = max - min;
	arr = (int *)malloc(sizeof(int) * num);
	if (arr == 0)
		return (-1);
	*range = arr;
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (i);
}
