#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        int i = 1/0;
        printf("Divisão por zero!\n");
    } else {
        int status;
        int child_pid = wait(&status);
        printf("filho acabou, %d\n", child_pid);
        printf("Error - %d\n", WIFEXITED(status));
        printf("Signal - %d\n", WIFSIGNALED(status));
        printf("%s\n", strsignal(WTERMSIG(status)));
    }
    

    return 0;
}