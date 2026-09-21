#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bibilioteca.h"

int main()
{
    FILE *arquivo;
    char filename[50];

    for (int i = 0; i < 11; i++){
        for (int j = 4; j <= 4096; j *= 2 ){
            sprintf(filename,"./entradas/alunos_%d.csv", j);

            arquivo = fopen("filename", "r");

            if (arquivo != NULL){

                fclose(arquivo);
            }
        }
    }   
    
    Aluno alunos[5];
    strcpy(alunos[0].nome, "Joao");
    strcpy(alunos[1].nome, "Francine");
    strcpy(alunos[2].nome, "Pedro");
    strcpy(alunos[3].nome, "Jose");
    strcpy(alunos[4].nome, "Carlos");

    OrdenarAlunos(alunos);

    printf("\nAlunos ordenados por nome (crescente):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nome: %s\n", alunos[i].nome);
    }

    DistribuiNotas(alunos);
    CalculaMedia(alunos);
    OrdenaAlunosDec(alunos);

    printf("\nAlunos ordenados por media (decrescente):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nome: %s | Media: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    return 0;
}