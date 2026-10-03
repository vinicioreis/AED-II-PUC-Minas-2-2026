#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    Aluno *alunos;
    FILE *arquivo;
    char filename[50];

    for (int i = 0; i < 5; i++) // repetir as 5x
    {
        sprintf(filename, "./entradas/alunos_%d.csv", j);

        for (int j = 4; j <= 4096; j *= 2)
        {

            sprintf(filename, "./entradas/alunos_%d.csv", j); // ele não lê arquivo nenhum. Ele monta um texto e guarda na variável filename, trocando o %d pelo valor atual de j

            arquivo = fopen(filename, "r");

            if (arquivo != NULL)
            {
                char linha[256];
                int n = 0;

                while (fgets(linha, sizeof(linha), arquivo) != NULL)
                {
                    n++;
                }

                rewind(arquivo);

                alunos = malloc(n * sizeof(Aluno));

                if (alunos == NULL)
                {
                    printf("Erro ao alocar memoria.\n");
                    fclose(arquivo);
                    return 1;
                }

                int quantidade = 0;

                while (fscanf(arquivo, "%49[^,],%f,%f,%f\n",
                              alunos[quantidade].nome,
                              &alunos[quantidade].notas[0],
                              &alunos[quantidade].notas[1],
                              &alunos[quantidade].notas[2]) == 4)
                {

                    quantidade++;
                }

                printf("Arquivo: %s  | Alunos lidos: %d\n",
                       filename, n, quantidade);

                fclose(arquivo);
                free(alunos);
            }
            else
            {
                printf("nao abriu : %s\n", filename);
            }
        }
    }
    return 0;
}