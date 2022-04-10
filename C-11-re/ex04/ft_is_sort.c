/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:52:56 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/23 09:56:59 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	asc;
	int	des;
	int	i;

	asc = 1;
	des = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			des = 0;
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 0;
		i++;
	}
	return (des || asc);
}
