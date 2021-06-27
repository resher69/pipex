/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 23:30:53 by agardet           #+#    #+#             */
/*   Updated: 2021/06/27 11:18:19 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipex_data_init(t_pdata data)
{
	data->path = 0;
	data->cmd1.command = 0;
	data->cmd1.fd = -1;
	data->cmd2.command = 0;
	data->cmd2.fd = -1;
}

int	pipex_pipe_init(t_pipe *u_pipe)
{
	if (pipe(u_pipe->tab) != 0)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);	
}

void	pipex_free_path(t_pdata data)
{
	int	i;

	i = 0;
	while (data->path && data->path[i])
		free(data->path[i++]);
	free(data->path);
	data->path = 0;
}
int		pipex_kill(t_pdata data)
{
	int	i;

	i = 0;
	pipex_free_path(data);
	while (data->cmd1.command && data->cmd1.command[i])
		free(data->cmd1.command[i++]);
	free(data->cmd1.command);
	data->cmd1.command = 0;
	i = 0;
	while (data->cmd2.command && data->cmd2.command[i])
		free(data->cmd2.command[i++]);
	free(data->cmd2.command);
	data->cmd2.command = 0;
	if (data->cmd1.fd > 0)
		close(data->cmd1.fd);
	if (data->cmd2.fd > 0)
		close(data->cmd2.fd);
	free(data);
	return (EXIT_FAILURE);
}
