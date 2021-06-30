/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:12:11 by agardet           #+#    #+#             */
/*   Updated: 2021/06/30 04:06:36 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipex_exec_cmd1(t_pdata data, t_pipe u_pipe, char **envp)
{
	char	*buf;
	char	*tmp;
	int		i;

	i = 0;
	dup2(data->cmd1.fd, 0);
	dup2(u_pipe.channel.write_fd, 1);
	close(u_pipe.channel.read_fd);
	close(u_pipe.channel.write_fd);
	close(data->cmd1.fd);
	close(data->cmd2.fd);
	buf = ft_strdup(data->cmd1.command[0]);
	while (data->path[i++])
	{
		tmp = ft_strjoin(ft_strjoin(data->path[i], "/"), buf);
		execve(tmp, &data->cmd1.command[0], envp);
	}
	perror(data->cmd1.command[0]);
}

void	pipex_exec_cmd2(t_pdata data, t_pipe u_pipe, char **envp)
{
	char	*buf;
	char	*tmp;
	int		i;

	i = 0;
	dup2(u_pipe.channel.read_fd, 0);
	dup2(data->cmd2.fd, 1);
	close(u_pipe.channel.read_fd);
	close(u_pipe.channel.write_fd);
	close(data->cmd1.fd);
	close(data->cmd2.fd);
	buf = ft_strdup(data->cmd2.command[0]);
	while (data->path[i++])
	{
		tmp = ft_strjoin(ft_strjoin(data->path[i], "/"), buf);
		execve(tmp, &data->cmd2.command[0], envp);
	}
	perror(data->cmd1.command[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pdata	data;
	t_pipe	u_pipe;
	int		tmp;

	data = malloc(sizeof(struct s_data));
	if (!data)
		return (EXIT_FAILURE);
	pipex_init(data);
	if (pipex_parsing(data, argc, argv, envp))
		return (pipex_kill(data));
	if (pipe_init(&u_pipe) != EXIT_SUCCESS)
		return (pipex_kill(data));
	if (fork() == 0)
		pipex_exec_cmd1(data, u_pipe, envp);
	else if (fork() == 0)
		pipex_exec_cmd2(data, u_pipe, envp);
	close(u_pipe.channel.read_fd);
	close(u_pipe.channel.write_fd);
	wait(&tmp);
	wait(&tmp);
	return (EXIT_SUCCESS);
}
