#include"../header.h"
#include<sys/ipc.h>
#include<sys/shm.h>
#define shm_key 2
#define shm_size 512
int main()
{
	int sh_id;
	char *shm_mem;
	sh_id=shmget(shm_key,shm_size,IPC_CREAT | 0666);
	if(sh_id==-1)
	{
		perror("failed to create a shared memory \n");
		exit(0);
	}
	shm_mem=(char *) shmat(sh_id,NULL,0);
	if(shm_mem==(char *)-1)
	{
		perror("failed of shmat \n");
		exit(0);
	}
	strncpy(shm_mem,"hello shared memory acessing ",sizeof(shm_mem));
	printf("read from the shared memory  :%s \n",shm_mem);
	if(shmdt(shm_mem)==-1)
	{
		perror("faield to delete the allocated memory \n");
		exit(0);
	}
}


