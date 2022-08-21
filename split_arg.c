/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/21 04:56:02 by akefeder         ###   ########.fr       */
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

int		ft_split_arg(t_data *data, char c)
{
	int	i;

	i = 0;
	{
		env->shrt = ft_strcopy_char(env->str, c, &i);
		i++;
		env->path = ft_strcopy_int(env->str, i);
		if (env->shrt == NULL || env->path == NULL)
			return (ERROR);
		return (OK);
	}
	else
		return (ERROR);
}
