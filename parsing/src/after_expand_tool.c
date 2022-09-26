/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_expand_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:32:18 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/23 17:22:55 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_split_space(t_data *data)
{
	char	*src;
	t_data	*slot;
	int		i;

	src = data->str;
	i = 0;
	slot = data->suiv;
	data->str = ft_strcopy_char(src, ' ');
	while (src[i] != ' ')
		i++;
	while (src[i] == ' ')
		i++;
	data->suiv = add_l_arg();
	data->suiv->str = ft_strcopy_int(src, &i);
	if (data->follow == 1)
	{
		data->follow = 0;
		data->suiv->follow = 1;
	}
	data->suiv->suiv = slot;
	free(src);
}