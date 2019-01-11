#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	mkfifo("fifo", 0644);
	int infd = open("file", O_RDONLY);
	if (infd == -1)
	{
		printf("open error!");
		exit(-1);
	}

	int outfd = open("fifo", O_WRONLY);
	if (outfd == -1)
	{
		printf("open error!");
		exit(-1);
	}

	char buf[1024];
	int n;
	while ((n = read(infd, buf, 1024)) > 0)
	{
		//write(outfd, buf, strlen(buf));
		write(outfd, buf, n);
	}
	close(infd);
	close(outfd);

	return 0;
}
