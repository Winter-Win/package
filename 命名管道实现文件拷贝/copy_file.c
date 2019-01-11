#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int outfd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfd == -1)
	{
		printf("open error!");
		exit(-1);
	}

	int infd = open("fifo", O_RDONLY);
	if (outfd == -1)
	{
		printf("open error!");
		exit(-1);
	}

	char buf[1024];
	int n;
	while ((n = read(infd, buf, 1024)) > 0)
	{
		//	write(outfd, buf, strlen(buf));
		write(outfd, buf, n);
	}
	close(infd);
	close(outfd);
	unlink("fifo");

	return 0;
}
