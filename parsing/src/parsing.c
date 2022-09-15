/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:21:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/15 10:59:01 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*parsing(char *s)
{
	t_data	*printer;
	t_data	*data;
	int i;

	if (check_space(s) == ERROR)
		return (NULL);
	if (check_error_parse(s) == ERROR)
		return (gest_error(ERR_CHECK, NULL), NULL);
	data = ft_quot_esp_split(s);
	if (data == NULL)
		return (gest_error(ERR_SPLIT, data), NULL);
	
	printer = data;
	i = 0;
	while (printer != NULL)
	{
		printf("%i : |%s| / Follow : %i\n", i, printer->str, printer->follow);
		i++;
		printer = printer->suiv;
	}
	gest_error(END, data);
	return (data);
}