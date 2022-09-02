/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:44:59 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/02 13:56:26 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data*	add_l_arg(void)
{
	t_data	*slot;

	slot = malloc(1 * sizeof(t_data));
	if (slot == NULL)
		return (NULL);
	slot->suiv = NULL;
	slot->str = NULL;
	return (slot);
}

// int		add_l_arg(t_data *data)
// {
// 	// t_data	*tmp;
// 	t_data	*slot;
// 	t_data	*flow;

// 	// data = *data;
// 	slot = malloc(1 * sizeof(t_data));
// 	if (slot == NULL)
// 		return (ERROR);
// 	slot->suiv = NULL;
// 	if (!data)
// 	{
// 		data = slot;
// 		printf("j'ai pas encore plante\n");
// 	}
// 	else
// 	{
// 		flow = data;
// 		while (flow->suiv != NULL)
// 			flow = flow->suiv;
// 		flow->suiv = slot;
// 	}
// 	// *data = tmp;
// 	data->i = 0;
// 	printf("j'ai pas encore plante %i\n", data->i);
// 	return (OK);
// }