/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:57:52 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/02 21:25:49 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strchr(const char *s, int c) {
  int i;

  i = 0;
  while (s[i]) {
    if ((char)c == s[i])
      return (((char *)s + i));
    i++;
  }
  if ((char)c == '\0')
    return ((char *)s + i);
  return (NULL);
}
