/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:21:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/25 17:00:04 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int parsing(char *s, t_data *data)
{
	t_data	*printer;
	int i;

	if (ft_split_arg(data, '=', s) == ERROR)
		return (ERROR);
	printer = data;
	i = 0;
	while (printer != NULL)
	{
		printf("%i : %s\n", i, printer->str);
		i++;
		printer = printer->suiv;
	}
	return (OK);
}