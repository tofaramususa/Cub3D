/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:23:36 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/05 15:00:46 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int as)
{
	return ((as <= 127) && (as >= 0));
}