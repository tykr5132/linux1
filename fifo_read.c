#include"../header.h"
int main()
{
	int fd;
	char buf[40];
	fd=open("myfifo",O_RDONLY);
	if(fd==-1)
	{
		perror("faield to open the fifo\n");
		exit(0);
	}
	read(fd,buf,sizeof(buf));
	printf("the message from fifo is :%s\n",buf);
	return 0;
	close(fd);
}
