/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:21:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/15 00:12:21 by akefeder         ###   ########.fr       */
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
	if (data == NULL)
		return (gest_error(ERR_SPLIT, data), NULL);
	data = ft_search_expand(data, env);
	if (data == NULL)
		return (gest_error(ERR_SPLIT, data), NULL);
	data = ft_after_expand(data);
	if (data == NULL)
		return (gest_error(ERR_SPLIT, data), NULL);
	data = ft_last_error(data);
	if (data == NULL)
		return (gest_error(ERR_SPLIT, data), NULL);
	if (data == NULL)
		return (NULL);
	printer = data;
	i = 0;
	while (printer != NULL)
	{
		printf("%i : |%s| / Follow : %i / Token : %i\n", i, printer->str, printer->follow, printer->token);
		i++;
		printer = printer->suiv;
	}
	//exit_code = 2;
	gest_error(END, data);
	return (data);
}