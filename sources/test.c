#include "../includes/pipex.h"
#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
    printf("caca");
    int i = 0;
    t_pdata data;
    char *buf;

    	while (envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			data->path = ft_split((*envp + 5), ':');
			break ;
		}
		++envp;
	}
	buf = ft_strdup("cat");
	while (data->path[i++])
	{
		ft_strjoin(data->path[i - 1], buf);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char *dst;

	if (!s1)
		return (NULL);
	if ((dst = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	res = ft_memset(res, 0, total_len);
	ft_strcat(res, (char *)s1);
	ft_strcat(res, (char *)s2);
	res[total_len] = 0;
	return (res);
}

char	*ft_strcat(const char *dst, const char *src)
{
	int		i;
	int		j;
	char	*dst_cpy;
	char	*src_cpy;

	i = 0;
	j = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	while (dst_cpy[i])
		i++;
	while (src_cpy[j])
	{
		dst_cpy[i + j] = src[j];
		j++;
	}
	dst_cpy[i + j] = 0;
	return (dst_cpy);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *s;

	if (!(s = malloc(count * size)))
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

static size_t	count_sep(const char *s, char c)
{
	size_t	i;
	size_t	nb_sep;
	char	*s_cpy;

	s_cpy = (char *)s;
	i = 0;
	nb_sep = 0;
	while (s_cpy[i])
	{
		while ((s_cpy[i] == c) && (s_cpy[i]))
			i++;
		while ((s_cpy[i] != c) && (s_cpy[i]))
			i++;
		if (s_cpy[i] == c && (s_cpy[i]))
			nb_sep++;
		if (s_cpy[i - 1] != c && (s_cpy[i] == 0))
			nb_sep++;
	}
	return (nb_sep);
}

static char		**free_tab(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs_split;
	char	*start;
	size_t	i;

	if ((!s) || !(strs_split = ft_calloc(sizeof(char *),
											(count_sep(s, c) + 1))))
		return (NULL);
	if ((count_sep(s, c) == 0))
		return (strs_split);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		if (start != s)
			if (!(strs_split[i++] = ft_strndup(start, (s - start))))
				return (free_tab(strs_split));
	}
	strs_split[i] = NULL;
	return (strs_split);
}

char	*ft_strndup(char *src, size_t size)
{
	char	*dst;
	size_t	i;

	if (!src)
		return (NULL);
	if (!(dst = (char *)ft_calloc(sizeof(char), (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, 0, n);
}