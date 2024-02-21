char	*get_next_line(int fd)
{
	int		i = 0;
	int		rd = 0;
	char	c;
	char	*buff = malloc(100000);

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while ((rd = read(fd, &c, 1)) > 0)
	{
		buff[i++] = c;
		if (c == '\n')
			break ;
	}
	buff[i] = '\0';
	if (rd == -1 || i == 0 || (!buff[i - 1] && !rd))
		return (free(buff), NULL);
	return (buff);
}
