/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:32:18 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/18 15:10:32 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *env, char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0' && env[i] != '\0' && str[i] == env[i])
		i++;
	if (str[i] == '\0' && env[i] == '=')
		return (FOUND);
	return (N_FOUND);
}

int ft_strstrcmp(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp(env[i], str) == FOUND)
			return (i);
		i++;
	}
	return (ERROR);
}

char	*ft_strjoin(char **str)
{
	int		len;
	char	*cpy;
	int		i;
	int		j;

	len = ft_strllen(str);
	cpy = malloc((len + 1) * sizeof(char));
	len = 0;
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while(str[i][j] != '\0')
		{
			cpy[len] = str[i][j];
			len++;
			j++;
		}
		i++;
	}
	cpy[len] = '\0';
	free_str(str);
	return (cpy);
}