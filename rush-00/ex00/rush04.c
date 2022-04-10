/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayi <hayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:20:03 by hayi              #+#    #+#             */
/*   Updated: 2022/02/07 15:42:05 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	drawing(int cur_x, int cur_y, int x, int y)
{
	if (cur_x == 0 && cur_y == 0)
		ft_putchar('A');
	else if (cur_x == x - 1 && cur_y == y - 1 && y != 1 && x != 1)
		ft_putchar('A');
	else if (cur_x == x - 1 && cur_y == 0)
		ft_putchar('C');
	else if (cur_x == 0 && cur_y == y - 1)
		ft_putchar('C');
	else if (cur_x == 0 || cur_y == 0 || cur_y == y - 1 || cur_x == x - 1)
		ft_putchar('B');
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
