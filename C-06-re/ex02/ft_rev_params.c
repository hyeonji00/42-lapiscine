/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:41:25 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/15 19:43:19 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	cnt;
	int	i;

	cnt = argc - 1;
	while (cnt > 0)
	{
		i = 0;
		while (argv[cnt][i] != '\0')
		{
			write(1, &argv[cnt][i], 1);
			i++;
		}
		write(1, "\n", 1);
		cnt--;
	}
}
