/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/17 22:19:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Find the largest number of the array, called max, x is the number of digit in max

#include <stdio.h>
#include <stdlib.h>

int		numbers_in_max(int max)
{
	int	x;

	if (max == 10)
		return (2);
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

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int stock;

	i = 0;
	stock = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - i))
		{
			if (tab[i] > tab[i + j])
			{
				stock = tab[i];
				tab[i] = tab[i + j];
				tab[i + j] = stock;
			}
			j++;
		}
		i++;
	}
}

int	*copy_tab(int *a, int size)
{
	int *c;
	int	i;

	c = malloc(sizeof(int) * size);
	if (!c)
		return (NULL);
	i = 0;
	while (size--)
	{
		c[i] = a[i];
		i++;
	}
	return (c);
}

void	simplify_list(int *a, int size)
{
	int	*c;
	int	i;
	int	j;

	c = copy_tab(a, size);
	ft_sort_int_tab(c, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a[i] == c[j])
				a[i] = j;
			j++;
		}
		i++;
	}
	free(c);
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
	simplify_list(a, size);

	min = get_min(a, size);
	printf("\nmin2 = %d\n", min);
	max = get_max(a, size);
	printf("max2 = %d\n", max);

	x= numbers_in_max(max);
	printf("x = %d\n", x);

	//1- Trier en fonction des unites
	//2- Trier en fonction des dizaines
	//3- etc ...
	//Use counting sort to sort the elements inside radix
	size = 0;
}

int	main(void)
{
	int *a;

	a = malloc(sizeof(int) * 11);
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
	a[10] = 7549;

	int size;
	size = 0;

	while (a[size])
		size++;
	printf("size = %d\n", size);

	radix(a, size);

	int i;

	printf("\nListe :\n");
	i = 0;
	while (i < 10)
	{
		printf("%d\n", a[i]);
		i++;
	}

	free(a);
	return (0);
}
