/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:12:11 by agardet           #+#    #+#             */
/*   Updated: 2021/06/27 11:18:18 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>


void	pipex_exec_cmd1(t_pdata data, t_pipe pipe, char **envp)
{
	char	*buf;
	int		i;

	i = 0;
	dup2(data->cmd1.fd, 0);
	dup2(pipe.channel.write_fd, 1);
	close(pipe.channel.read_fd);
	close(pipe.channel.write_fd);
	close(data->cmd1.fd);
	close(data->cmd2.fd);
	buf = ft_strdup(data->cmd1.command[0]);
	while (data->path[i++])
	{
		execve(buf, &data->cmd1.command[0], envp);
		ft_strjoin(data->path[i - 1], buf);
	}
	perror(data->cmd1.command[0]);
}

void	pipex_exec_cmd2(t_pdata data, t_pipe pipe, char **envp)
{
	char	*buf;
    char    *tmp;
	int		i;

	i = 0;
	dup2(data->cmd2.fd, 0);
	dup2(pipe.channel.write_fd, 1);
	close(pipe.channel.read_fd);
	close(pipe.channel.write_fd);
	close(data->cmd1.fd);
	close(data->cmd2.fd);
	buf = ft_strdup(data->cmd2.command[0]);
	while (data->path[i++])
	{
		execve(tmp, &data->cmd2.command[0], envp);
		tmp = ft_strjoin(data->path[i - 1], buf);
	}
	perror(data->cmd2.command[0]);
}

int main(int argc, char **argv, char **envp)
{
    t_pdata	data;
    t_pipe  u_pipe;
    int        tmp;
    (void)argc;
    (void)argv;
    data = malloc(sizeof(struct s_data));
    if (!data)
        return (EXIT_FAILURE);
    pipex_data_init(data);
    if (pipex_parsing(data, argc, argv, envp) != EXIT_SUCCESS)
        pipex_kill(data);
    if (pipex_pipe_init(&u_pipe) != EXIT_SUCCESS)
        pipex_kill(data);
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