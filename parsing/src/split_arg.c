/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/21 10:40:12 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcopy_char_a(char *str, char c, int	*i)
{
	int		len;
	char	*cpy;

	len = ft_strlen_char(str, c);
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while(str[(*i)] != '\0' && str[(*i)] != c)
	{
		cpy[(*i)] = str[(*i)];
		(*i)++;
	}
	cpy[(*i)] = '\0';
	return (cpy);
}

int		ft_split_arg(t_data *data, char c, char *src)
{
	int	i;
	t_data	*slot;

	i = 0;
	while (src[i] != '\0')
	{
		if (add_l_arg(slot) == ERROR)
			return (ERROR);
		if (!data)
			data = slot;
		while(slot->suiv != NULL)
			slot = slot->suiv;
		slot->str = ft_strcopy_char_a(src, c, &i);
		if (slot->str == NULL)
			return (ERROR);
		while(src[i] == " ")
			i++;
	}
	else
		return (ERROR);
}
