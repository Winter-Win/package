#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX_CMD  1024
char command[MAX_CMD];//定义一个全局数组

//解析命令行输入的命令
int do_face()
{
	memset(command, 0x00, MAX_CMD);
	printf("[win@localhost shell]&& ");
	fflush(stdout);
	if (scanf("%[^\n]%*c", command) == 0)
	{
		getchar();
		return -1;
	}
	return 0;
}

//提取字符串命令
char **do_parse(char *buf)
{
	//把空格替换成为'\0'
	int argc = 0;
	static char *argv[32];
	char *ptr = buf;

	while (*ptr != '\0')
	{
		if (!isspace(*ptr))//判断是不是空格
		{
			argv[argc++] = ptr;
			while ((!isspace(*ptr)) && (*ptr) != '\0')
			{
				ptr++;
			}
		}
		else
		{
			while (isspace(*ptr))
			{
				*ptr = '\0';
				ptr++;
			}
		}
	}
	argv[argc] = NULL;
	return argv;
}

//解析重定向功能
int do_redirect(char *buff)
{
	char *ptr = buff, *file = NULL;//file的作用是提取重定向符号后面的文件名
	int type = 0, fd, redirect_type = -1;
	while (*ptr != '\0')
	{
		if (*ptr == '>')
		{
			*ptr++ = '\0';
			redirect_type++;
			if (*ptr == '>')
			{
				*ptr++;
				redirect_type++;
			}
			while (isspace(*ptr))//过滤掉多余的空格，让ptr一直往后走
			{
				ptr++;
			}
			file = ptr;
			while ((!isspace(*ptr)) && *ptr != '\0')
			{
				ptr++;
			}
			*ptr = '\0';
			if (redirect_type == 0)
			{
				fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			}
			else
			{
				fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
			}
			dup2(fd, 1);
		}
		ptr++;
	}
	return 0;
}

int do_exec(char *buff)
{
	char **argv = { NULL };
	int pid = fork();
	if (pid == 0)
	{
		do_redirect(buff);
		argv = do_parse(buff);
		if (argv[0] == NULL)
		{
			exit(-1);
		}
		execvp(argv[0], argv);
	}
	else
	{

		waitpid(pid, NULL, 0);
	}
	return 1;
}

int main()
{
	int num = 0;
	while (1)//死循环，让自己的shell命令能够一直继续输入操作
	{
		if (do_face() < 0)
		{
			continue;
		}
		do_exec(command);
	}

	return 0;
}