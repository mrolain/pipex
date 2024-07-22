/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:26:10 by mrolain           #+#    #+#             */
/*   Updated: 2024/07/19 07:50:32 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/libft/libft.h"

void	exec_cmd(char *argv, char **envp)
{
	char	**args;
	char	*cmdpath;

	args = ft_split(argv, ' ');
	if (!args)
		exit(1);
	cmdpath = ft_strjoin("/bin/", args[0]);
	if (!cmdpath)
		exit(1);
	if (execve(cmdpath, args, envp) == -1)
	{
		perror("command not found");
		exit(1);
	}
	exit(1);
}

void	child(char **argv, char **envp, int pipefd[2])
{
	int		infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY | O_CREAT, 0777);
	if (infile == -1)
	{
		perror("infile");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec_cmd(argv[2], envp);
}

void	parent(char **argv, char **envp, int pipefd[2])
{
	int		outfile;

	close(pipefd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("outfile");
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	exec_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			return (1);
		}
		pid = fork();
		if (pid == 0)
			child(argv, envp, pipefd);
		else
		{
			wait(NULL);
			parent(argv, envp, pipefd);
		}
	}
	else
	{
		write(1, "wrong argument.", 15);
		exit (1);
	}
	return (0);
}
