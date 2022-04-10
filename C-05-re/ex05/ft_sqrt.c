/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:10:55 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/17 17:23:42 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	n;
	unsigned int	i;

	n = (unsigned int)nb;
	if (n < 0)
		return (0);
	if (n < 2)
		return (n);
	i = 2;
	while (i * i < n)
	{
		i++;
	}
	if (i * i == n)
		return (i);
	return (0);
}
