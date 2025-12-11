/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:08:53 by tchumbas          #+#    #+#             */
/*   Updated: 2025/12/09 11:43:17 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (size > 0 && nmemb <= SIZE_MAX / size)
	{
		ptr = malloc(nmemb * size);
		if (!ptr)
			return (malloc(0));
		i = 0;
		while (i < size * nmemb)
		{
			((unsigned char *)ptr)[i] = 0;
			i++;
		}
		return (ptr);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;
	char			*p;

	if (!s)
		return (NULL);
	i = 0;
	chr = (unsigned char)c;
	p = (char *)s;
	while (*(p + i))
	{
		if (*(p + i) == chr)
			return (p + i);
		i++;
	}
	if (chr == '\0')
		return (p + i);
	return (NULL);
}

char	*append_line(char *old, char const *buf)
{
	char	*new;
	size_t	in;
	size_t	ib;

	if (!buf || !*buf)
		return (old);
	new = ft_calloc(ft_strlen_nl(old) + ft_strlen_nl(buf) + 2, 1);
	if (!new)
	{
		free(old);
		return (NULL);
	}
	in = 0;
	while (old && old[in])
	{
		new[in] = old[in];
		in++;
	}
	free(old);
	ib = 0;
	while (buf[ib] && buf[ib] != '\n')
		new[in++] = buf[ib++];
	if (buf[ib] == '\n')
		new[in++] = '\n';
	return (new);
}

char	*read_until_nl(int fd, char *buf, char *line, int iv)
{
	t_read_to_nl_vars	vars;

	while (!ft_strchr(buf, '\n'))
	{
		line = append_line(line, buf);
		if (!line)
			return (NULL);
		vars.bytesread = read(fd, buf, BUFFER_SIZE);
		if (vars.bytesread <= 0)
		{
			buf[0] = '\0';
			if (vars.bytesread < 0)
				return (NULL);
			return (line);
		}
		buf[vars.bytesread] = '\0';
	}
	line = append_line(line, buf);
	if (!line)
		return (NULL);
	vars.buf_len_nl = ft_strlen_nl(buf) + 1;
	while (buf[vars.buf_len_nl] && vars.buf_len_nl < BUFFER_SIZE)
		buf[iv++] = buf[vars.buf_len_nl++];
	buf[iv] = '\0';
	return (line);
}
