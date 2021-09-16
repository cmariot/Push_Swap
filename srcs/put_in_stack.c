/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:49:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 15:48:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Atoi and check if the values are correctly formated */
int	ft_atoi_check(char *str, int *a, int j)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			len--;
		i++;
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	}
	a[j] = ft_atoi(str);
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return (-1);
	if (len != ft_intlen(a[j]))
		return (-1);
	return (0);
}

/* Put the values of argv into the stack a, and 0 in stack b */
int	ft_put_in_stack(int *a, int *b, char **argv, int j)
{
	int	i;
	int	stack_size;

	stack_size = 0;
	while (argv[stack_size] != NULL)
		stack_size++;
	if (j == 0)
		stack_size--;
	i = 0;
	while (i < stack_size)
	{
		if (ft_atoi_check(argv[j++ + 1], a, i) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		b[i++] = 0;
	}
	if (check_duplication(a, stack_size) == 0)
		return (1);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}
