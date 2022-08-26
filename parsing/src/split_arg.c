/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/26 03:57:45 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcopy_char_a(char *str, char c, int *i)
{
	int		len;
	char	*cpy;
	int		j;

	j = *i;
	len = ft_strlen_char_i(str, c, j);
	j = 0;
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while(str[(*i)] != '\0' && str[(*i)] != c)
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[(j)] = '\0';
	return (cpy);
}

t_data	*ft_split_arg(char c, char *src)
{
	int	i;
	t_data	*slot;
	t_data	*flow

	i = 0;
	while (src[i] != '\0')
	{
		if (data)
		{
			while(slot.suiv != NULL)
			{
				slot = *slot.suiv;
			}
		}
		if (!data)
			data = &slot;
		slot.str = ft_strcopy_char_a(src, c, &i);
		if (slot.str == NULL)
			return (ERROR);
		while(src[i] == ' ')
			i++;
	}
	return (OK);
}
