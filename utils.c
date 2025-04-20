/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:54:24 by nfoughal          #+#    #+#             */
/*   Updated: 2022/12/20 15:42:43 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path_split)
{
	int	i;

	i = -1;
	while (path_split[++i])
		free(path_split[i]);
	free(path_split);
}

char	*ft_return(char *cmd)
{
	if (!cmd || !*cmd)
		return (0);
	if (cmd[0] == '.')
		return (cmd + 2);
	if (cmd[0] == '/')
		return (cmd);
	return (0);
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	**path_split;
	int		i;
	char	*temp;

	i = -1;
	if (cmd[0] == '.' || cmd[0] == '/' || !cmd || !*cmd)
		return (ft_return(cmd));
	while (env[++i])
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			path_split = ft_split(env[i] + 5, ':');
	i = -1;
	while (path_split[++i])
	{
		temp = path_split[i];
		path_split[i] = ft_strjoin(temp, "/");
		free(temp);
		path = ft_strjoin(path_split[i], cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	free_path(path_split);
	return (0);
}

void	error(void)
{
	perror("Error");
	exit(1);
}

void	get_execve(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	if (!argv || !*argv)
		error();
	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], env);
	if (!path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		error();
	}
	if (execve(path, cmd, env) == -1)
		error();
}
