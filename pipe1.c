#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
	int fd[2];
	char buf[30];
	if(pipe(fd)==-1)
	{
		perror("failed to create the pipe \n");
		exit(0);
	}
	int ret=fork();
	if(ret==0)
	{
		close(fd[0]);
		char msg[]="hello yaswanth kumar reddy";
		write(fd[1],msg,sizeof(msg));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("the message in side the pipe is :%s\n",buf);
		close(fd[0]);
	}
}
