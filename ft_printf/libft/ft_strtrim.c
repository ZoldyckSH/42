/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:02:05 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/26 15:06:26 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		min;
	size_t		max;
	size_t		len;

	if (!s)
		return (NULL);
	min = 0;
	while (s[min] != '\0'
			&& (s[min] == ' ' || s[min] == '\n' || s[min] == '\t'))
		min++;
	max = ft_strlen(s);
	while (min < max
			&& (s[max - 1] == ' ' || s[max - 1] == '\n' || s[max - 1] == '\t'))
		max--;
	if (min == max)
		return (ft_strnew(1));
	len = max - min;
	return (ft_strsub(s, min, len));
}
