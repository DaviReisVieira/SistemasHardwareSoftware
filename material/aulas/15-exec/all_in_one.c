#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


// Crie um programa que recebe números via scanf, executa eh_par em um processo filho e usa seu valor de retorno para decidir se o número é par ou não. Seu programa deverá parar de receber números quando eh_par retornar -1.
int main(int argc, char *argv[]) { 
    int num;
    while (scanf("%d", &num) == 1) {
        char str[10];
        sprintf(str, "%d", num);
        int filho = fork();
        if (filho == 0) {
            char prog[] = "./eh_par";
            char *args[] = {"./eh_par", str, NULL}; 

            execvp(prog, args);
        }
        else {
            int status;
            wait(&status);
            printf("%d\n", WEXITSTATUS(status));
            if (WEXITSTATUS(status) == 1) {
                printf("%d eh par\n", num);
            }
            else if (WEXITSTATUS(status) == 255) {
                printf("%d eh negativo\n", num);
            }
            else {
                printf("%d eh impar\n", num);
            }
            
        }
    }
    return 0;
}
