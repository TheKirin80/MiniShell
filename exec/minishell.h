#ifndef MINISELL_H
# define MINISELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>

char	**split_cmd(char *s, char sep);
int	find_index(char *str, char c);
char	*path_join(char *path, char *bin);
int	str_ncmp(char *str1, char *str2, int n);
char	*str_ndup(char *str, unsigned int n);
void	write_error_minishell(char *msg);

/*temporaire*/
int find_nb_pipe(char *s);

#endif