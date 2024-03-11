/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:50:25 by davmoren          #+#    #+#             */
/*   Updated: 2024/02/27 19:53:49 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char	*to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k] && to_find[k] != '\0')
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
