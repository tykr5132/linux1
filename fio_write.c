#include"../header.h"
int main()
{
	int fd;
	int ret;
	ret=mkfifo("myfifo",0666);
	if(ret==-1)
	{
		perror("failed to create the fifo\n");
		exit(0);
	}
	char msg[]="hello yaswanth kumar reddy tiyyagura";
	fd=open("myfifo",O_WRONLY);
	if(fd==-1)
	{
		perror("failed to open the fifo\n");
		exit(0);
	}
	write(fd,msg,sizeof(msg));
	printf("the message to be sent %s\n",msg);
	close(fd);
}

