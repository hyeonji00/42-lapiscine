/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:37:01 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/16 17:49:45 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	cnt;
	int	i;

	cnt = 1;
	while (cnt < argc)
	{
		i = 0;
		while (argv[cnt][i] != '\0')
		{
			write(1, &argv[cnt][i], 1);
			i++;
		}
		write(1, "\n", 1);
		cnt++;
	}
}
