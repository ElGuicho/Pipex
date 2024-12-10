/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:59:13 by gmunoz            #+#    #+#             */
/*   Updated: 2024/12/10 17:10:21 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
	{
		ft_putstr_fd("pipex: memory allocation error\n", 2);
		exit(1);
	}
	path = get_path(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(1);
	}
	execve(path, s_cmd, env);
	ft_putstr_fd("pipex: execve error\n", 2);
	ft_free_tab(s_cmd);
	exit(1);
}

void	child(char **argv, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(argv[1], 0);
	if (dup2(fd, 0) == -1 || dup2(p_fd[1], 1) == -1)
	{
		ft_putstr_fd("pipex: dup2 in child failed\n", 2);
		exit(1);
	}
	close(p_fd[0]);
	exec(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int		fd;
	int		status;

	waitpid(-1, &status, 0);
	fd = open_file(argv[4], 1);
	if (dup2(fd, 1) == -1 || dup2(p_fd[0], 0) == -1)
	{
		ft_putstr_fd("pipex: dup2 in parent failed\n", 2);
		exit(1);
	}
	close(p_fd[1]);
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
	{
		ft_putstr_fd("pipex: pipe error\n", 2);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("pipex: fork error\n", 2);
		exit(1);
	}
	if (!pid)
		child(argv, p_fd, env);
	parent(argv, p_fd, env);
	return (0);
}
