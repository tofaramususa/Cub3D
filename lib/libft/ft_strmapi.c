/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:57:29 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/05 15:01:29 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*s1;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (s1 == NULL)
		return (NULL);
	ft_memset(s1, 0, len + 1);
	len = 0;
	while (s[len])
	{
		s1[len] = f(len, s[len]);
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
