#include <unistd.h>
#include <stdio.h>


// Se o programa for chamado com menos de 2 argumentos mostrar mensagem de erro e sair.
// Se o programa for chamado com 2 ou mais argumentos, mostrar no terminal a soma deles.
int main(int argc, char *argv[]) {
    int soma = 0;

    if (argc < 2) {
        printf("Erro: faltam argumentos\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        soma += num;
    }
    printf("Soma: %d\n", soma);
    return 0;
}
