#include "minishell.h"

char	*getpath(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	//Je parcour l'env pour trouver la ligne commancant par "PATH=".
	while (env[i] && str_ncmp(env[i], "PATH=", 5))
		i++;
	//Si je ne trouve pas la ligne je balance quand meme la commande l'erreur est automatiquement gerer.
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	//Ici je test chaque bout de path commancant par ':' avec access().
	while (path && find_index(path, ':') > -1)
	{
		dir = str_ndup(path, find_index(path, ':'));
		//Je rajoute un '/' entre dir et cmd.
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		//je saute le n caracteres jusqu'au prochain ':'
		path += find_index(path, ':') + 1;
	}
	return (cmd);
}


void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	//Je split les espaces.
	args = split_cmd(cmd, ' ');
	//Si il y'a un '/' dans ma ligne je considere qu'on me donne le chemin de la commande.
	if (find_index(args[0], '/') > -1)
		path = args[0];
	//Si non je cherche le chemin d'en l'env.
	else
		path = getpath(args[0], env);
	execve(path, args, env);
	write_error_minishell(cmd);
}

void	redir(char *cmd, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	//Je cree un enfant.
	pid = fork();
	//Si je suis sur le parent jattend que l'enfant se termine.
	if (pid)
	{
		waitpid(pid, NULL, 0);
	}
	//Si je suis l'enfant j'execute la commande.
	else
	{
		exec(cmd, env);

	}
}

int	main(int argc, char **argv, char **env)
{
	char	*s;
	int		i;

	while (1)
	{
		//Ici je me prepare a recevoir une ligne.
		s = readline("minishell : ");
		//J' ajoute simplement l'historique des commandes.
		add_history(s);
		/*
			Ici j'appellerai ton parsing.
		*/
		//fonctions temporaire pour avancer sans parsing.
		int nb_pipe = find_nb_pipe(s);
		char **cmd = split_cmd(s, '|');
		i = 0;
		while (i <= nb_pipe)
		{
			printf("test\n");
			redir(cmd[i], env);
			i++;
		}
	}
	return (0);
}
