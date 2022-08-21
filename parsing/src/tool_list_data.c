/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:44:59 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/21 10:39:45 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		add_l_arg(t_data *data)
{
	t_data	*slot;
	t_data	*flow;

	slot = malloc(1 * sizeof(t_data));
	if (slot == NULL)
		return (ERROR);
	slot->suiv = NULL;
	if (!data)
		data = slot;
	else
	{
		flow = data;
		while (flow->suiv != NULL)
			flow = flow->suiv
		flow->suiv = slot;
	}
	return (OK);
}