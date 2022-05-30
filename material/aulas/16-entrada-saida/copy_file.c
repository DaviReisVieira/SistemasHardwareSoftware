// Em um novo arquivo copy_file.c, crie um programa copy_file que recebe dois nomes de arquivos como argumentos no terminal e copia o conteúdo do primeiro para o segundo. Ou seja, você deverá

//     abrir ambos arquivos (cada um terá seu próprio file descriptor)
//     ler do primeiro para um buffer
//     escrever este buffer no segundo
/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

int main (int argc, char *argv[]) {
    char arq1[100]; // nomes do arquivo, recebido via scanf
    char arq2[100]; // nomes do arquivo, recebido via scanf
    char buf[1]; // local usado para guardar os dados lidos de arq1
    
    scanf("%s %s", arq1, arq2);
    int fd1 = open(arq1, O_RDONLY);
    int fd2 = open(arq2, O_WRONLY | O_CREAT, 0700);

    int j = 1;
    while (j!=0) {
        j = read(fd1, buf, 1);
        printf("Caracter lido: %c\n", buf[0]);
        if (j == 0) {
            printf("Arquivo vazio\n");
            break;
        } else {
            write(fd2, buf, 1);
            
        }
    }
    close(fd1);
    close(fd2);
    
    return 0;
}