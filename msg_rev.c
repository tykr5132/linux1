#include"../header.h"
 struct message1
{
	long type;
	char message[40];
};
int main(int argc, char *argv[])
{
	struct message1 msg;
	int key1=atoi(argv[1]);
	key_t key;
	int msg_id;
	key=ftok("progfile",key1);
	if(key==-1)
	{
		perror("failed to create the key \n");
	}
	msg_id=msgget(key,0666);
	if(msg_id==-1)
	{
		perror("failed to create the message id\n");
		exit(0);
	}
	if(msgrcv(msg_id,&msg,sizeof(msg.message),1,0)==-1)
	{
		perror("failed to send the message \n");
		exit(0);
	}
	printf("recived message :%s\n",msg.message);
	msgctl(msg_id,IPC_RMID,NULL);
	return 0;
}



