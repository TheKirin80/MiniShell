/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:10:55 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/02 13:57:52 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv)
{
	char	*s;
	t_data	*data;

	//rempli_env(char **env);
	
	if (argc > 1)
		return (printf("L'executable n'a pas de parametre\n") , ERROR);
	(void)argv;
	while (1)
	{
		//Ici je me prepare a recevoir une ligne.
		s = readline("minishell : ");
		data = parsing(s);
		//J' ajoute simplement l'historique des commandes.
		//add_history(s);
		if (data == NULL)
			printf("Fail command\n");

	}
	return (0);
}
