/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:21:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/23 17:13:03 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_data	*parsing(char *s, char **env)
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
	data = ft_pipe_redir(data);
	data = ft_search_expand(data, env);
	data = ft_after_expand(data);
	if (data == NULL)
		return (NULL);
	
	//data = ft_expand(data, env)
	printer = data;
	i = 0;
	while (printer != NULL)
	{
		printf("%i : |%s| / Follow : %i / Token : %i\n", i, printer->str, printer->follow, printer->token);
		i++;
		printer = printer->suiv;
	}
	gest_error(END, data);
	return (data);
}