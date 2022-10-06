/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_error_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:10:29 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/06 02:15:59 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	ft_cmp_token(t_data *data)
{
	if (data && data->token > ARG && data->token < S_QUOTE)
		return (FOUND);
	return (N_FOUND);
}