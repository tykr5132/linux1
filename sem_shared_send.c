#include"../header.h"
#include<sys/ipc.h>
#include<sys/shm.h>
#define shm_key1 2
#define shm_key2 3
#define shm_size 512
int main(int argc,char *argv[])
{
	key_t key=atoi(argv[1]);
	char *shm_mem;
	int shm_id;
	shm_id=shmget(key,shm_size,IPC_CREAT |0666);
	if(shm_id==-1)
	{
		perror("failed to create the shmget \n");
		exit(0);
	}
	shm_mem=(char *)shmat(shm_id,NULL,0);
	if(shm_mem==(char*)-1)
	{
		perror("failed the function of shmat\n");
		exit(0);
	}
	strncpy(shm_mem,argv[2],sizeof(shm_mem));
	printf("the message is :%s\n",shm_mem);
	if(shmdt(shm_mem)==-1)
	{
		perror("failed to detach the memory\n");
		exit(0);
	}
	return 0;
}
	


