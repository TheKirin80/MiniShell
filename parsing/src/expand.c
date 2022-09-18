/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:22:14 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/18 15:13:59 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dollar_case(char **exp, int i)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = '$';
	ret[1] = '\0';
	free(exp[i]);
	return ret;
}

char	*n_found_case(char **exp, int i)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = '\0';
	free(exp[i]);
	return (ret);
}

char	*switch_env_case(char **exp, char **env, int j, int i)
{
	int		k;

	k = 0;
	while (env[i][k] != '=')
		k++;
	k++;
	free(exp[j]);
	return (ft_strcopy_int(env[i], &k));
}

char	*modif_exp(char **exp, int j, char **env)
{
	int i;

	while (exp[j] != NULL)
	{
		i = 0;
		if (exp[j][0] == '\0')
			exp[j] = dollar_case(exp, j);
		else
		{
			i = ft_strstrcmp(env, exp[j]);
			if (i == ERROR)
				exp[j] = n_found_case(exp, j);
			else
				exp[j] = switch_env_case(exp, env, j, i);
		}
		j++;
	}
	return (ft_strjoin(exp));
}

void	ft_expand(t_data *data, char **env)
{
	int		len_deb;
	char	**exp;
	int		i;
	int		j;
	
	len_deb = ft_count_compare(data->str, '$');
	exp = malloc((len_deb + 1) * sizeof(char *));
	i = 0;
	j = 0;
	len_deb = 0;
	if (data->str[i] != '$')
		len_deb = 1;
	while(data->str[i]!= '\0')
	{
		if (data->str[i] == '$')
			i++;
		exp[j] = ft_strcopy_char_i(data->str, '$', &i);
		j++;
	}
	exp[j] = NULL;
	j = len_deb;
	free(data->str);
	data->str = modif_exp(exp , j, env);
}