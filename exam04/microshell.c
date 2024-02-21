#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

static int	perr(char *s)
{
	while (*s)
		write(2, s++, 1);
	return (1);
}

static int	cd(char **av, int i)
{
	if (i != 2)
		return (perr("error: cd: bad arguments\n"));
	else if (chdir(av[1]) == -1)
		return (perr("error: cd: cannot change directory to "), perr(av[1]), perr("\n"));
	return (0);
}

static int	exec(char **av, char **envp, int i)
{
	int	status;
	int	fds[2];
	int	has_pipe = (av[i] && !strcmp(av[i], "|"));

	if (has_pipe && pipe(fds) == -1)
		return (perr("error: fatal\n"));
	int	pid = fork();
	if (pid == 0)
	{
		av[i] = 0;
		if (has_pipe && (dup2(fds[1], 1) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1))
			return (perr("error: fatal\n"));
		execve(*av, av, envp);
		return (perr("error: cannot execute "), perr(*av), perr("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fds[0], 0) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1))
		return (perr("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	int	status = 0;

	while (*av && *(av + 1))
	{
		av++;
		int	i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (!strcmp(*av, "cd"))
			status = cd(av, i);
		else if (i)
			status = exec(av, envp, i);
		av += i;
	}
	return (status);
}
