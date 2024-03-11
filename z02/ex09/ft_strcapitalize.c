/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:33:50 by davmoren          #+#    #+#             */
/*   Updated: 2024/03/05 19:33:29 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void	capitalize_char(char *c, int new_word)
{
	if (new_word && is_lowercase(*c))
		*c -= 32;
	else if (!new_word && is_uppercase(*c))
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			capitalize_char(&str[i], new_word);
			new_word = !is_alphanumeric(str[i + 1]);
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
