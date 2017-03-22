/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:12:31 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/13 15:05:29 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct stat	t_stat;
void	sh_loop(char **env);
void	sh_prompt(char ***env);
void	fork_process(char *path, char **env, char **av);
void	sh_execute_bin(char *av, char ***env, char **paths);
int		sh_get_env_pos(char *find, char **env);
char	*sh_get_env(char *find, char **env);
char	**sh_parse_env(char *find, char **env);
char	*sh_search_bin(char *line, char *dirpath);
int		sh_access(char *path);
int		sh_isbin(char *path);
void	sh_builtin_exit(char **av);
int		sh_search_builtin(char *av, char ***env);
void	sh_builtin_cd(char **av, char ***env);
void	sh_builtin_cd_open(char *dir, char ***env);
void	sh_builtin_env(char **av, char ***env);
void	sh_builtin_setenv(char **av, char ***env);
void	sh_builtin_setenv_add(char *name, char *value, char ***env);
void	sh_builtin_setenv_replace(char *name, char *value, char **env);
void	sh_builtin_setenv_mng(char *name, char *value, char ***env);
void	sh_builtin_unsetenv(char **av, char ***env);
void	sh_free_memory(char *line, char **av, char **paths);
char	**sh_save_env(char ***env);
void	sh_signals(void);
void	sh_wrong_exit(int signum, char *son);
pid_t	save_cpid(pid_t *father);
char	*sh_replace_home(char *path, char **env);
void	sh_execute_cmd(char *line, char ***sh_env, char **paths);
void	sh_notfound(char *av);
#endif
