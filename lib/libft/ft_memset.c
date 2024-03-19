/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:33:31 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/05 15:01:03 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memset(void *b, int n, size_t value)
{
	unsigned char	*bp;

	bp = (unsigned char *)b;
	while (value--)
	{
		*bp = (unsigned char)n;
		bp++;
	}
	return (b);
}
