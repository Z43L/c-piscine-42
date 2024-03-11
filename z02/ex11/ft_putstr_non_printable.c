/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:51:46 by davmoren          #+#    #+#             */
/*   Updated: 2024/03/05 19:33:52 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	print_char('\\');
	print_char(hex_digits[c / 16]);
	print_char(hex_digits[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 32 || c > 126)
		{
			print_hex(c);
		}
		else
		{
			print_char(c);
		}
		i++;
	}
}
