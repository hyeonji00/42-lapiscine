/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayi <hayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:19:32 by hayi              #+#    #+#             */
/*   Updated: 2022/02/07 15:39:32 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	drawing(int cur_x, int cur_y, int x, int y)
{
	if ((cur_x == 0 || cur_x == x - 1) && (cur_y == 0 || cur_y == y - 1))
		ft_putchar('o');
	else if (cur_x == 0 || cur_x == x - 1)
		ft_putchar('|');
	else if (cur_y == 0 || cur_y == y - 1)
		ft_putchar('-');
	else
		ft_putchar(' ');
}

void	moving(int x, int y)
{
	int	cur_x;
	int	cur_y;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < y)
	{
		while (cur_x < x)
		{
			drawing(cur_x, cur_y, x, y);
			cur_x++;
		}
		cur_x = 0;
		ft_putchar('\n');
		cur_y++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	moving(x, y);
}
