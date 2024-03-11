/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:05:54 by davmoren          #+#    #+#             */
/*   Updated: 2024/03/03 17:01:58 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i >= 2)
	{
		return (i);
	}
	else
	{
		return (0);
	}
}

int	convert_to_base(char *str, char *base, int base_len, int sign)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (get_index(str[i], base) != -1)
	{
		nbr = nbr * base_len + get_index(str[i], base);
		i++;
	}
	return (nbr * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	base_len;

	i = 0;
	sign = 1;
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (convert_to_base(&str[i], base, base_len, sign));
}
