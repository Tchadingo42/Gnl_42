#include "get_next_line.h"

static	char		*ft_strnjoin(const char *s1, const char *s2, int size)
{
	char		*src;
	char		*dest;

	src = ft_strnew(ft_strlen(s1) + size + 1);
	dest = src;
	while (*s1)
	{
		*src++ = *s1++;
	}
	while (size-- && *s2)
	{
		*src++ = *s2++;
	}
	return (dest);
}

static	int 		ft_words_size(char *str)
{
	size_t		words_nbr;
	char		delim;

	delim = '\n';
	words_nbr = 0;
	while (str[words_nbr] != delim && str[words_nbr] != '\0')
	{
		words_nbr += 1;
	}
	return (words_nbr);
}

static	void		ft_fill(char buff_static[BUFF_SIZE], char *buff)
{
	size_t		i;
	size_t		size;

	size = BUFF_SIZE;
	i = 0;
	while (buff[i] != '\0')
	{
		buff_static[i] = buff[i];
		i++;
	}
	while (i <= size)
	{
		buff_static[i] = 0;
		i++;
	}
}

static	size_t		ft_algo(char buff[BUFF_SIZE], char *line, int size)
{
	if (!line[0] && !buff[0])
		buff[0] = 0;
	else
		ft_fill(buff, &(buff[size + 1]));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static	char	buff[4096][BUFF_SIZE + 1];
	char		*tmp;
	int		ret;
	int		size;

	ret = 1;
	if (fd == -1 || !line)
		return (-1);
	*line = ft_strnew(1);
	while (ret == 1)
	{
		if (!buff[fd][0])
			ret = read(fd, &buff[fd], BUFF_SIZE);
		if (ret < 0)
			return (1);
	size = ft_words_size(buff[fd]);
	tmp = *line;
	*line = ft_strnjoin(tmp, buff[fd], size);
	free(tmp);
	if (*line[0] && !buff[fd][0] || buff[fd][size])
		return (ft_algo(buff[fd], *line, size));
	ft_strclr((char*)&buff[fd]);
	}
	return (0);
}
