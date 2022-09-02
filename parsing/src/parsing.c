/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:21:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/02 16:14:19 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*parsing(char *s)
{
	t_data	*printer;
	t_data	*data;
	int i;

	data = ft_split_arg(' ', s);
	if (data == NULL)
	{
		printf("je suis la \n");
		return (NULL);
	}
	printer = data;
	i = 0;
	while (printer != NULL)
	{
		printf("%i : |%s|\n", i, printer->str);
		i++;
		printer = printer->suiv;
	}
	return (data);
}