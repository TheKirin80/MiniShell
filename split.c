/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:28:20 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/20 23:08:42 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcopy(char *str)
{
	int		len;
	int		i;
	char	*cpy;

	i = 0;
	len = ft_strlen(str);
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while(str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strcopy_int(char *str, int i)
{
	int		len;
	int		j;
	char	*cpy;

	j = 0;
	len = ft_strlen_int(str, i);
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while(str[i] != '\0')
	{
		cpy[j] = str[i];
		j++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strcopy_char(char *str, char c, int	*i)
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

int		ft_split_env_c(t_env *env, char c)
{
	int	i;
	t_env	*slot;

	i = 0;
	slot = env;
	while(slot->suiv != NULL)
	{
		i = 0;
		slot->shrt = ft_strcopy_char(slot->str, '=', &i);
		i++;
		slot->path = ft_strcopy_int(slot->str, i);
		if (slot->shrt == NULL || slot->path == NULL)
			return (ERROR);
		slot = slot->suiv;
	}
	return (OK);
}

int		ft_split_env(t_env *env, char c)
{
	int	i;

	i = 0;
	if (env != NULL)
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