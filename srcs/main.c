/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:53:13 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 16:08:27 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_zeros(int *a, int stack_size)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	while (stack_size--)
	{
		if (a[i] == 0)
			zero++;
		i++;
	}
	if (zero > 1)
	{
		return (-1);
	}
	return (zero);
}

int	check_duplication(int *a, int stack_size)
{
	int	i;
	int	j;
	int	zero;

	i = 0;
	zero = ft_check_zeros(a, stack_size);
	if (zero > 1 || zero == -1)
	{
		return (-1);
	}
	while (a[i + 1])
	{
		j = i + 1;
		while (j <= stack_size)
		{
			if (a[i] == a[j])
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_put_in_stack(int *a, int *b, int stack_size, char **argv)
{
	int	i;

	i = 0;
	while (stack_size - i)
	{
		if (*argv[i + 1] == '\0')
		{
			ft_putstr_fd("Error\nNULL argument.\n", 2);
			return (-1);
		}
		a[i] = ft_atoi(argv[i + 1]);
		b[i] = 0;
		if (ft_strlen(argv[i + 1]) != ft_intlen(a[i]) && *argv[i + 1] != '0')
		{
			ft_putstr_fd("Error\nInvalid argument.\n", 2);
			return (-1);
		}
		i++;
	}
	if (check_duplication(a, stack_size) != -1)
		return (1);
	ft_putstr_fd("Error\nDuplication.\n", 2);
	return (-1);
}

void	print_stack(int *a, char c, int stack_size)
{
	int	i;
	int	len;

	ft_putstr_fd("\n --- Stack ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(" ---\n", 1);
	i = 0;
	len = 0;
	while (stack_size--)
	{
		ft_putchar_fd(c, 1);
		ft_putchar_fd('[', 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("] = ", 1);
		len = ft_intlen(a[i]);
		while (len++ != 11)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(a[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		stack_size;
	int		*a;
	int		*b;

	if (argc == 1)
		return (0);
	stack_size = (argc - 1);
	a = malloc(sizeof(int) * stack_size);
	b = malloc(sizeof(int) * stack_size);
	if (!a || !b)
		return (-1);
	if (ft_put_in_stack(a, b, stack_size, argv) == 1)
	{
		print_stack(a, 'a', stack_size);
		print_stack(b, 'b', stack_size);
	}
	free(a);
	free(b);
	return (0);
}
