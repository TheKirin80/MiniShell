/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:08:02 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/11 12:38:46 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_compare(char src, char *cmp)
{
	int	j;

	j = 0;
	while (cmp[j] != '\0')
	{
		if (src == cmp[j])
			return (OK);
		j++; 
	}
	return (ERROR);
}