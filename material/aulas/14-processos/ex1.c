#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int create_children(pid_t pai,int variavel){
    pid_t filho;

    if (variavel > 7){
        return;
    }

    filho = fork();

    if (filho == 0) {
        // processo filho aqui
        pai = getppid();
        filho = getpid();
        variavel++;
        printf("Eu sou um processo filho, pid=%d, ppid=%d, meu id do programa é %d\n", 
            filho, pai, variavel);
        create_children(filho, variavel);
    }

}

int main() {
    pid_t pai, filho;
    int variavel = 0;


    filho = fork();
    if (filho == 0) {
        create_children(pai, variavel);
    } else {
        // processo pai aqui!
        pai = getpid();
        printf("Eu sou o processo pai, pid=%d, meu id do programa é %d\n", 
            pai, variavel);
    }
    return 0;
    
}
