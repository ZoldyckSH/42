/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:43:43 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 21:42:12 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**check_path(char **env)
{
	int		i;
	char	**envv;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] == 0)
		return (NULL);
	envv = ft_strsplit(&env[i][5], ':');
	return (envv);
}

int		check_tab(char **tab)
{
	if (access(*tab, F_OK) == -1)
	{
		ft_error("minishell: command not found: ", *tab);
		return (-1);
	}
	if (access(*tab, X_OK) == -1)
	{
		ft_error("minishell: permission denied: ", *tab);
		return (-1);
	}
	return (0);
}

int		run_cmd(char *name, char **env, char **tab)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(name, tab, env) == -1)
			return (-1);
		return (0);
	}
	else
		wait(&pid);
	return (0);
}

char	**exec_final(char **cmd, char **env, char **tab)
{
	char	*ret;
	char	*name;

	if (ft_check_str(*tab, '/') == 1)
	{
		if (check_tab(tab) == -1)
			return (NULL);
		run_cmd(*tab, env, tab);
		return (NULL);
	}
	cmd = check_path(env);
	if ((ret = parsing_cmd(cmd, tab)) == NULL)
		return (cmd);
	name = ft_sous_d(ret, *tab);
	if (run_cmd(name, env, tab) == -1)
	{
		ft_strdel(&name);
		ft_error("error ", *tab);
		return (cmd);
	}
	ft_strdel(&name);
	return (cmd);
}
