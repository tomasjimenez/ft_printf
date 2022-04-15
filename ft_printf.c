/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojimene <tojimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:15:23 by tojimene          #+#    #+#             */
/*   Updated: 2022/04/15 21:58:10 by tojimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(long long int num, int base, char *charbase)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += write (1, "-", 1);
		len += print_num (-num, base, charbase);
	}
	else
	{
		if (num > (base - 1))
			len += print_num (num / base, base, charbase);
		len += write (1, &charbase[num % base], 1);
	}
	return (len);
}

static	int	print_pointer(uintptr_t num, int base, char *charbase)
{
	int	len;

	len = 0;
	len += write (1, "0x", 2);
	if (num > (base - 1))
			len += print_num (num / base, base, charbase);
	len += write (1, &charbase[num % base], 1);
	return (len);
}

static int	evaluate_char(char str, va_list arg, int *len)
{
	if (str == 'c')
		print_char(va_arg(arg, int), len);
	else if (str == 's')
		print_str(va_arg(arg, char *), len);
	else if (str == '%')
		*len += write (1, "%%", 1);
	else if (str == 'i' || str == 'd')
		*len += print_num(va_arg(arg, int), 10, "0123456789");
	else if (str == 'x')
		*len += print_num(va_arg(arg, unsigned int), 16, "0123456789abcdef");
	else if (str == 'X')
		*len += print_num(va_arg(arg, unsigned int), 16, "0123456789ABCDEF");
	else if (str == 'u')
		*len += print_num(va_arg(arg, unsigned int), 10, "0123456789");
	else if (str == 'p')
		*len += print_pointer(va_arg(arg, uintptr_t), 16, "0123456789abcdef");
	return (*len);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str != '%')
			len += write (1, str, 1);
		else
		{
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 'x'
				|| *str == 'X' || *str == '%')
				evaluate_char (*++str, arg, &len);
			else if (*str != '\0')
				len += write(1, str, 1);
		}
		if (*str != '\0')
			str++;
	}
	va_end (arg);
	return (len);
}
// int main(void)
// {
// 	// int d = printf("hola mundo\n");
// 	// printf("he impreso: %d", d);

// 	//char c[]= "hola%d";
// 	//printf("%d", ft_printf(c));
// 	//char *d;
// 	ft_printf("%s\n", "hola");
// 	//printf("%s\n", "hola");
// 	//printf("%p\n", &d);
// }