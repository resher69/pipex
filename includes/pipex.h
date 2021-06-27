#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_data
{
	struct s_cmd1	
	{
		char	**command;
		int		fd;
	}		cmd1;
	struct s_cmd2	
	{
		char	**command;
		int		fd;
	}	cmd2;
	char	**path;
}t_data, *t_pdata;

typedef union u_pipe 
{
	struct s_channel
	{
		int	read_fd;
		int	write_fd;
	}	channel;
	int	tab[2];
}	t_pipe;


int		pen_file(const char *path, int flags, int perm);
void	pipex_data_init(t_pdata data);
int		pipex_pipe_init(t_pipe *u_pipe);
int 	pipex_parsing(t_pdata data, int argc, char **argv, char **envp);
void	pipex_free_path(t_pdata data);
int		pipex_kill(t_pdata data);
void	pipex_exec_cmd1(t_pdata data, t_pipe pipe, char **envp);
void	pipex_exec_cmd2(t_pdata data, t_pipe pipe, char **envp);
#endif