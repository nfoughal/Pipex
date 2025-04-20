/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:22:34 by nfoughal          #+#    #+#             */
/*   Updated: 2022/12/19 13:11:11 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

char	*get_path(char *cmd, char **env);
void	error(void);
void	get_execve(char *argv, char **env);
void	free_path(char **path_split);
#endif