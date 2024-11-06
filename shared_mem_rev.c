#include"../header.h"
#define shm_key 2
#include<sys/ipc.h>
#include<sys/shm.h>
#define shm_size 512
int main()
{
	int sh_id;
	char *shm_mem;
	sh_id=shmget(shm_key,shm_size,0666);
	if(sh_id==-1)
	{
		perror("failed to create shmgt \n");
		exit(0);
	}
	shm_mem=(char *) shmat(sh_id,NULL,0);
	if(shm_mem ==(char *)-1)
	{
		perror("failed to shmat \n");
		exit(0);
	}
	printf("the information in shared memoy is :%s\n",shm_mem);
	if(shmdt(shm_mem)==-1)
	{
		perror("failed to delete the allocated memory\n");
		exit(0);
	}
	return 0;
}

