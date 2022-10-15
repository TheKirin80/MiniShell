/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:10:55 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/15 14:46:13 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_data	*data;
	char	**usenv = env;

	(void)env;
	if (argc > 1)
		return (printf("L'executable n'a pas de parametre\n") , ERROR);
	(void)argv;
	s = readline("minishell : ");

	while (s)	
	{
		data = parsing(s, usenv);
		if (data == NULL)
			free(s);
		s = readline("minishell : ");
	}
	return (0);
}
