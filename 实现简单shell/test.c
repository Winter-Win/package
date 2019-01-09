#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define NUM 32

int main()
{
	char cmd[MAX];
	char *myargv[NUM];
	for (;;)
	{
		printf("[win@localhost haha]# ");
		fflush(stdout);
		fgets(cmd, MAX, stdin);
		cmd[strlen(cmd) - 1] = 0;

		int i = 0;
		myargv[i] = strtok(cmd, " ");
		i++;
		while (i)
		{
			char *p = strtok(NULL, " ");
			if (p == NULL)
			{
				myargv[i] = NULL;
				break;
			}
			myargv[i] = p;
			i++;
		}
		pid_t id = fork();
		if (id < 0)
		{

		}

		else if (id == 0)
		{
			//child
			execvp(myargv[0], myargv);
		}

		else
		{
			waitpid(id, NULL, 0);
		}
	}
	//for(i = 0;myargv[i] != NULL; i++)
	//{
	//	printf("%d: %s\n", i, myargv[i]);
	//}
	return 0;
}