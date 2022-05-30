#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Crie um programa eh_par que recebe um inteiro como argumento de linha de comando e cujo main retorne 1 se o número for par, 0 caso contrário e -1 se ele for negativo.
int main(int argc, char *argv[]) {
    printf("Iniciando funcao");
    int num = atoi(argv[1]);
    if (num < 0) {
        printf("eh_par: -1\n");
        return -1;
    }
    if (num % 2 == 0) {
        printf("eh_par: 1\n");
        return 1;
    }
    printf("eh_par: 0\n");
    return 0;   

}
