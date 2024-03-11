/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:42:57 by davmoren          #+#    #+#             */
/*   Updated: 2024/03/05 21:59:38 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while ((src[i] != '\0') && (size > 1))
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (i);
}
