/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:21:12 by davmoren          #+#    #+#             */
/*   Updated: 2024/03/05 21:53:42 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	const char	*hex_digits = "0123456789abcdef";

	print_char(hex_digits[c / 16]);
	print_char(hex_digits[c % 16]);
}

void	print_memory_line(unsigned char *addr, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < 16)
	{
		if (i < size)
			print_hex(addr[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			print_char(' ');
	}
	i = -1;
	while (++i < size)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			print_char(addr[i]);
		else
			print_char('.');
	}
	print_char('\n');
}

void	print_address(void *addr)
{
	const char			*hex_digits = "0123456789abcdef";
	unsigned long long	address;
	char				result[16];
	int					i;

	address = (unsigned long long)addr;
	i = 16;
	while (i--)
	{
		result[i] = hex_digits[address % 16];
		address /= 16;
	}
	write(1, result, 16);
	write(1, ": ", 2);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	line_size;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address(ptr + i);
		if (size - i < 16)
		{
			line_size = size - i;
		}
		else
		{
			line_size = 16;
		}
		print_memory_line(ptr + i, line_size);
		i += 16;
	}
}
