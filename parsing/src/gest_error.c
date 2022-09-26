/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:44:08 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/18 15:32:40 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_parse(t_data *data)
{
	t_data *tmp;
	
	tmp = NULL;
	while (data != NULL)
	{
		tmp = data->suiv;
		if (data->str != NULL)
			free(data->str);
		free(data);
		data = tmp;
	}
}

void	gest_error(int code_err, t_data *data)
{
	if (code_err == ERR_CHECK)
		printf("COMMAND DONT RESPECT THE FORMAT\n");
	else if (code_err == ERR_SPLIT)
	{
		free_parse(data);
		printf("PROBLEM WITH COMMAND\n");
	}
	else if (code_err == END)
		free_parse(data);
	
}