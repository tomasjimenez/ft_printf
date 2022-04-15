/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojimene <tojimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:21:50 by tojimene          #+#    #+#             */
/*   Updated: 2022/04/15 21:46:05 by tojimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char str, int *len)
{
	*len += write (1, &str, 1);
	return (*len);
}

int	print_str(char	*str, int *len)
{
	if (!*str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
	return (*len);
}
