/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/17 19:54:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Find the largest number of the array, called max, x is the number of digit in max

#include <stdio.h>
#include <stdlib.h>

int		numbers_in_max(int max)
{
	int	x;

	x = 1;
	while (max > 10)
	{
		max /= 10;
		x++;
	}
	return (x);
}

int		get_max(int *a, int size)
{
	int max;

	max = a[0];
	while (size--)
	{
		if (*a > max)
			max = *a;
		a++;
	}
	return (max);
}

int		get_min(int *a, int size)
{
	int	min;

	min = a[0];
	while (size--)
	{
		if (min > *a)
			min = *a;
		a++;
	}
	return (min);
}

int		get_next_min(int *a, int size, int previous_min)
{
	int	new_min;

	new_min = previous_min;
	while (size--)
	{
		if (new_min < *a)
		{
			new_min = *a;
		}
		a++;
	}
	return (new_min);
}

void	simplify_list(int *a, int size, int min)
{
	int	simplified;
	int	size_backup;
	int	i;

	simplified = 0;
	size_backup = size;
	while (size--)
	{
		i = 0;
		min = get_next_min(a, size_backup, simplified);
		while (a[i] != min)
			i++;
		a[i] = simplified;
		simplified++;
	}
}

void	radix(int *a, int size)
{
	int	min;
	int	max;
	int	x;

	min = get_min(a, size);
	printf("min = %d\n", min);
	max = get_max(a, size);
	printf("max = %d\n", max);
	//Simplifier la liste pour qu'on ait plus de negatifs a gerer, de 0 a N avec N entier positif
	//-54 5 364 42 -> 0 1 3 2
	//simplify_list(a, size, min);
	x= numbers_in_max(max);
	printf("x = %d\n", x);
	while (x--)
	{
		printf("Sort\n");
	}
	//1- Trier en fonction des unites
	//2- Trier en fonction des dizaines
	//3- etc ...
	//Use counting sort to sort the elements inside radix
	size = 0;
}

int	main(void)
{
	int *a;

	a = malloc(sizeof(int) * 10);
	if (!a)
		return (-1);
	a[0] = 304;
	a[1] = 223;
	a[2] = 534;
	a[3] = -643;
	a[4] = 86;
	a[5] = 865;
	a[6] = 456;
	a[7] = 1;
	a[8] = 9;
	a[9] = 79;

	int size;
	size = 0;

	while (a[size])
		size++;
	printf("size = %d\n", size);

	radix(a, size);

	free(a);
	return (0);
}
