/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:18:10 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/20 23:11:17 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef	struct s_env	t_env;

struct s_data
{
	char	**str;
	t_token	token;
	t_data	*suiv;
};

struct	s_env
{
	char	*str;
	char	*shrt;
	char	*path;
	t_env	*suiv;
}

#endif