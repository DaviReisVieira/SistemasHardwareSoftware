#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int rodando = 1;
    pid_t filho;

    filho = fork();

    if (filho == 0) {
        printf("Filho: %d\n", getpid());
        printf("Acabei filho\n");
        rodando = 0;
    } else { 
        printf("Esperando o filho acabar!\n");
        waitpid(filho, NULL, 0);
        printf("Acabei pai\n");
    }
    return 0;
}
