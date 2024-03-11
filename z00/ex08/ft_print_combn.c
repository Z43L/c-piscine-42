/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:03:09 by davmoren          #+#    #+#             */
/*   Updated: 2024/03/05 05:19:52 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(int *comb, int n)
{
	char	digit;
	int		i;

	i = 0;
	while (i < n)
	{
		digit = comb[i] + '0';
		write(1, &digit, 1);
		i++;
	}
	if (!(comb[0] == 10 - n && comb[n - 1] == 9))
	{
		write(1, ", ", 2);
	}
}

void	ft_combn_recursive(int n, int k, int *comb)
{
	int	start;

	if (k == n)
	{
		print_combination(comb, n);
		return ;
	}
	if (k == 0)
		start = 0;
	else
		start = comb[k - 1] + 1;
	comb[k] = start;
	while (comb[k] < 10)
	{
		ft_combn_recursive(n, k + 1, comb);
		comb[k]++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	if (n < 1 || n > 9)
		return ;
	ft_combn_recursive(n, 0, comb);
}
