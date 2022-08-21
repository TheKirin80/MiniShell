/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:47:32 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/21 04:57:41 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_strlen_int(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] != NULL)
	{
		j++;
		i++;
	}	
	return (j);
}

int	ft_strlen_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != NULL && str[i] != c)
		i++;
	return (i);
}

int	ft_strlen_char(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] != NULL && str[i] != c)
	{
		i++;
		j++;
	}	
	return (i);
}

int	ft_strllen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}


