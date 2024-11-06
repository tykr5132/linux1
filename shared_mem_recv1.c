#include"../header.h"
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#define shm_key1 2
#define shm_key2 3
#define shm_size 512
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
void intialize_semaphore(int shm_id)
{
	union semun sem_union;
	sem_union.val=1;
	if(semctl(shm_id,0,SETVAL,sem_union)==-1)
	{
		perror("failed to intialize the semaphore\n");
		exit(1);
	}
}
void semaphore_lock(int shm_id)
{
	struct sembuf sem_op;
	sem_op.sem_num=0;
	sem_op.sem_op=-1;
	sem_op.sem_flg=0;
	if(semop(shm_id,&sem_op,1)==-1)
	{
		perror("failed to lock \n");
		exit(1);
	}
}
void semaphore_unlock(int shm_id)
{
	struct sembuf sem_op;
	sem_op.sem_num=0;
	sem_op.sem_op=1;
	sem_op.sem_flg=0;
	if(semop(shm_id,&sem_op,1)==-1)
	{
		perror("failed to unlock\n");
		exit(1);
	}
}
int main(int argc,char *argv[])
{
	key_t key=atoi(argv[1]);
	char *shm_mem;
	int shm_id;
	shm_id=shmget(key,shm_size,0666);
	if(shm_id==-1)
	{
		perror("failed to create the shmget \n");
		exit(0);
	}
	intialize_semaphore(shm_id);
	shm_mem=(char *)shmat(shm_id,NULL,0);
	if(shm_mem==(char*)-1)
	{
		perror("failed the function of shmat\n");
		exit(0);
	}
	semaphore_lock(shm_id);
	printf("the message is :%s\n",shm_mem);
	semaphore_unlock(shm_id);
	if(shmdt(shm_mem)==-1)
	{
		perror("failed to detach the memory\n");
		exit(0);
	}
	return 0;
}
	


