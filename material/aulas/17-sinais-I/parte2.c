#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("%d\n", getpid());
        while(1) {} 
    } else {
        int status;
        int child_pid = wait(&status);
        printf("Pai ID: %d\n", getpid());
        printf("filho acabou, %d\n", child_pid);
        printf("Error - %d\n", WIFEXITED(status));
        printf("Signal - %d\n", WIFSIGNALED(status));
        printf("%s\n", strsignal(WTERMSIG(status)));
    }
    

    return 0;
}