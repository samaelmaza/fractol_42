/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:58:41 by sreffers          #+#    #+#             */
/*   Updated: 2025/11/04 19:06:08 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_double(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if(s[i] == '+' || s[i] =='-')
		i++;
	while(s[i])
	{
		if(s[i] == '.')
		{
			dot++;
			i++;
		}
		if(s[i] < '0' || s[i] > '9')
			return 0;
		i++;
	}
	if(dot > 1)
		return 0;
	return 1;
}

int is_valid(char **av, int size)
{
	int	i;
	i = 2;
	while(i < size)
	{
		if(!is_double(av[i]) || atodbl(av[i]) > 2.00 || atodbl(av[i]) < -2.00)
			return 0;
		i++;
	}
	return 1;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	size_t	test;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		test = write(fd, &s[i], 1);
		(void) test;
		i++;
	}
}
