/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:44:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/15 15:17:04 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_split_slot(t_data *data)
{
	char	*src;
	t_data	*save;
	int		i;

	src = data->str;
	i = 0;
	while (src && src[i] != '\0')
	{
		if (src[i] == '<')
			
		
	}
	
}