/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 01:31:58 by agardet           #+#    #+#             */
/*   Updated: 2021/06/27 11:18:17 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>


int	open_file(const char *path, int flags, int perm)
{
	int		fd;

	fd = open(path, flags, perm);
	if (fd < 0)
		perror(path);
	else if (read(fd, NULL, 0) < 0)
	{
		perror(path);
		close(fd);
		fd = -1;
	}
	return (fd);
}

int pipex_parsing(t_pdata data, int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (write(1, "usage: pipex <file1> <cmd1> <cmd2> <file2>\n", 44));
	while (envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			data->path = ft_split((*envp + 5), ':');
			break ;
		}
		++envp;
	}
    data->cmd1.fd = open_file(argv[1], O_RDONLY, 0);
    data->cmd2.fd = open_file(argv[4], O_RDWR | O_CREAT | O_TRUNC, 420);
	if (data->cmd1.fd < 0 || data->cmd2.fd < 0)
		return (EXIT_FAILURE);
	data->cmd1.command = ft_split(argv[2], ' ');
	data->cmd2.command = ft_split(argv[3], ' ');
	return (EXIT_SUCCESS);
}