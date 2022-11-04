/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:10:55 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 18:41:39 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int g_exit_ret;

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_data	*data;
	char	**usenv = env;

	//printf(TEST);
	g_exit_ret = 0;
	(void)env;
	if (argc > 1)
		return (printf("L'executable n'a pas de parametre\n") , ERROR);
	(void)argv;
	//printf(TEST);
	s = readline("minishell : ");

	while (s)	
	{
		//printf("main : %i\n", exit_code);
		data = parsing(s, usenv);
		if (data == NULL)
			free(s);
		s = readline("minishell : ");
	}
	return (0);
}
