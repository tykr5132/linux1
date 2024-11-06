#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[20];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {  // Child process
        close(pipefd[0]);  // Close the unused read end
        char message[] = "Hello from the child process!";
        write(pipefd[1], message, strlen(message) + 1);
	printf("inside the child :%s\n",message);
	sleep(10);
        close(pipefd[1]);  // Close the write end
    } else {  // Parent process
        close(pipefd[1]);  // Close the unused write end
        printf("inside the parent\n");
//	sleep(10);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Message from child: %s\n", buffer);
        close(pipefd[0]);  // Close the read end
    }
    return 0;
}
