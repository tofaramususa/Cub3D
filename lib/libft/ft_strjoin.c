/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:14:23 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/02 21:25:49 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2) {
  int s1_len;
  int s2_len;
  char *s12;
  int j;

  if (!s1 || !s2)
    return (NULL);
  s1_len = ft_strlen((char *)s1);
  s2_len = ft_strlen((char *)s2);
  s12 = (char *)malloc(s2_len + s1_len + 1);
  if (s12 == NULL)
    return (NULL);
  j = 0;
  ft_memcpy(s12, s1, s1_len);
  ft_memcpy(s12 + s1_len, s2, s2_len);
  s12[s2_len + s1_len] = '\0';
  return (s12);
}
