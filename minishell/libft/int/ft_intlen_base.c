/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:17:55 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:44:01 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_intlen_base(long nb, int base)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
