/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:30:07 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/02/24 12:30:58 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	int		x;
	int		y;
	int		size;
	char	empty;
	char	disturb;
	char	full;
}	t_map;

typedef struct s_result
{
	int	x;
	int	y;
	int	size;
}	t_result;

int		is_printable(char c);
int		ft_atoi(char *str);
int		is_valid_map(char *av, int fd);
void	print_error(void);
char	*read_input(void);
void	read_map(int fd);
char	*read_file(void);

#endif