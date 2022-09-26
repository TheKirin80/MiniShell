/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:10:55 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/23 17:19:22 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_data	*data;
	char	**usenv = env;

	//rempli_env(char **env);
	(void)env;
	if (argc > 1)
		return (printf("L'executable n'a pas de parametre\n") , ERROR);
	(void)argv;
	int i = 0;
	while (i < 10)	
	{
		//Ici je me prepare a recevoir une ligne.
		s = readline("minishell : ");
		data = parsing(s, usenv);
		//J' ajoute simplement l'historique des commandes.
		//add_history(s);
		if (data == NULL)
			free(s);
		i++;
	}
	return (0);
}
