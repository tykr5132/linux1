#include"../header.h"
struct message1
{
	long type;
	char message[30];
};
int main(int argc, char *argv[])
{
	struct message1 msg;
	key_t key;
	int key1=atoi(argv[1]);
	int msg_id;
	key=ftok("progfile",key1);
	if(key==-1)
	{
		perror("failed to create the file\n");
		exit(0);
	}
	msg_id=msgget(key,0666 | IPC_CREAT);
	if(msg_id==-1)
	{
		perror("faield to create the id\n");
		exit(0);
	}
	msg.type=1;
	strncpy(msg.message,argv[2],sizeof(msg.message-1));
	 msg.message[sizeof(msg.message) - 1] = '\0';
	if(msgsnd(msg_id,&msg,sizeof(msg.message),0)==-1)
	{
		perror("failed to send the message\n");
		exit(0);
	}
	printf("the sending message is :%s\n",msg.message);
}


