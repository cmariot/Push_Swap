/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_binary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:35:44 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/26 12:17:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_to_binary_array(unsigned int nb)
{
	char				*str;
	int					i;

	str = malloc(sizeof(char) * 33);
	if (!str)
		return (NULL);
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
	return (str);
}
