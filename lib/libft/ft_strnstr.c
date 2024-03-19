/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:11:30 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/05 15:01:33 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	length;

	length = ft_strlen((char *)needle);
	if (!length)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (*haystack && len >= length)
	{
		if (!ft_memcmp(haystack, needle, length) && length <= len)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
