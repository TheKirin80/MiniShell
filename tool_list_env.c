/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:37:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/08/20 23:27:03 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		add_l_env(char **env, t_env *my_env)
{
	t_env	*slot;
	t_env	*flow;

	slot = malloc (1 * sizeof(t_env));
	if (slot == NULL)
		return (ERROR);
	slot->str = ft_strcopy(my_env);
	if (slot->str == NULL)
		return (ERROR);
	if (ft_split_env(slot, '=') == ERROR)
		return (ERROR);
	slot->suiv = NULL;
	if (my_env != NULL)
	{
		flow = my_env;
		while (flow->suiv != NULL)
			flow =flow->suiv;
		flow->suiv = slot;
	}
	else
		my_env = slot;
	return (OK);
}

void	del_l_env()


t_env	*init_l_env(char **env)
{
	t_env	*my_env;
	int		i;

	my_env = NULL;
	while (env[i] != NULL)
	{
		if (add_l_env(env[i], my_env) == ERROR)
			return (my_env);
		i++;
	}
	return (my_env);
}
