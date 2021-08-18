/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:35:44 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/18 19:47:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int	ft_convert_to_binary(int nb)
{
	char *str;
	int i;

	i = 0;
	str = malloc(sizeof(char) * 4);
	while (nb > 0)
	{
		str[i] = '0' + (nb % 2);
		nb = nb / 2;
		i++;
	}
	str[i] = '\0';
	i = atoi(str);
	free(str);
	return (i);
}

int	main(void)
{
	int i;
	int result;

	i = 4;
	result = ft_convert_to_binary(i);
	printf("%d (decimal) = %d (binaire)\n", i, result);
	return (0);
}
