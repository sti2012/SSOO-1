char *argv0;

int cat(int fd, char *name)
{
	int nr, nw;
	char buf[SIZE];

	while(1)
	{
		nr = read(fd, buf, SIZE);

		if (nr == -1)
		{
		perror(name);
		exit(EXIT_FAILURE);
		}

		if (nr == 0)
		{
			/* code */
		}

	}
}