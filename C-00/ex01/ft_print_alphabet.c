/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:52:13 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/08 16:31:15 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_print_alphabet(void)
{
	char	ch;

	ch = 'a';
	while (ch <= 'z')
	{
		write(1, &ch, 1);
		ch++;
	}
}
