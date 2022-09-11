/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:08:02 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/11 12:14:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_compare(char *src, char *cmp)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] != '\0')
	{
		j = 0;
		while (cmp[j] != '\0')
		{
			if (src[i] == cmp[j])
				return (OK);
			j++; 
		}
		i++;
	}
	return (ERROR);
}