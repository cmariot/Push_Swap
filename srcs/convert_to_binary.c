/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:35:44 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/23 19:07:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_u128_fd(unsigned __int128 nb, int fd)
{
	char		*base_dec;

	base_dec = "0123456789";
	if ((nb >= 0) && (nb <= 9))
	{
		write(fd, &base_dec[nb], 1);
	}
	else
	{
		ft_putnbr_u128_fd(nb / 10, fd);
		write(fd, &base_dec[nb % 10], 1);
	}
}

unsigned __int128	atou128(char *str)
{
	unsigned __int128	ull;
	int					i;

	ull = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		ull = ull * 10 + (str[i++] - '0');
	return (ull);
}

unsigned __int128	ft_convert_to_binary(unsigned int nb)
{
	char				*str;
	int					i;
	unsigned __int128	u128;

	str = malloc(sizeof(char) * 33);
	if (!str)
		return (-1);
	str[32] = '\0';
	i = 31;
	while (nb > 0 && i >= 0)
	{
		str[i] = '0' + (nb % 2);
		nb = nb / 2;
		i--;
	}
	while (i != -1)
		str[i--] = '0';
	u128 = atou128(str);
	free(str);
	return (u128);
}
