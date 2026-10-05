#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    Aluno *alunos;
    FILE *arquivo;
    FILE *resultado;

    char filename[50];

    resultado = fopen("resultados.csv", "w");

    if (resultado == NULL)
    {
        printf("Erro ao criar arquivo de resultado.\n");
        return 1;
    }

    fprintf(resultado,
            "N;"
            "Bubble1;Merge1;Quick1;"
            "Bubble2;Merge2;Quick2;"
            "Bubble3;Merge3;Quick3;"
            "Bubble4;Merge4;Quick4;"
            "Bubble5;Merge5;Quick5\n");

    for (int j = 4; j <= 4096; j *= 2)
    {
        int bubble[5];
        int merge[5];
        int quick[5];

        for (int i = 0; i < 5; i++)
        {
            sprintf(filename, "./entradas/alunos_%d.csv", j);

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
                    fclose(resultado);
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

                fclose(arquivo);

                CalculaMedia(alunos, quantidade);

                Aluno *bubbleAlunos = malloc(quantidade * sizeof(Aluno));
                Aluno *mergeAlunos = malloc(quantidade * sizeof(Aluno));
                Aluno *quickAlunos = malloc(quantidade * sizeof(Aluno));

                if (bubbleAlunos == NULL ||
                    mergeAlunos == NULL ||
                    quickAlunos == NULL)
                {
                    printf("Erro ao alocar memoria para as copias.\n");

                    free(alunos);
                    free(bubbleAlunos);
                    free(mergeAlunos);
                    free(quickAlunos);

                    fclose(resultado);

                    return 1;
                }
                for (int k = 0; k < quantidade; k++)
                {
                    bubbleAlunos[k] = alunos[k];
                    mergeAlunos[k] = alunos[k];
                    quickAlunos[k] = alunos[k];
                }

                // Bubble
                bubble[i] = OrdenaAlunosDec(
                    bubbleAlunos,
                    quantidade);

                // Merge
                merge[i] = 0;

                mergeSort(
                    mergeAlunos,
                    0,
                    quantidade - 1,
                    &merge[i]);

                // Quick
                quick[i] = 0;

                quickSort(
                    quickAlunos,
                    0,
                    quantidade - 1,
                    &quick[i]);

                printf("N: %d | Repeticao: %d | "
                       "Bubble: %d | Merge: %d | Quick: %d\n",
                       quantidade,
                       i + 1,
                       bubble[i],
                       merge[i],
                       quick[i]);

                free(alunos);
                free(bubbleAlunos);
                free(mergeAlunos);
                free(quickAlunos);
            }
            else
            {
                printf("Nao abriu: %s\n", filename);
            }
        }
        fprintf(resultado,
                "%d;"
                "%d;%d;%d;"
                "%d;%d;%d;"
                "%d;%d;%d;"
                "%d;%d;%d;"
                "%d;%d;%d\n",
                j,
                bubble[0], merge[0], quick[0],
                bubble[1], merge[1], quick[1],
                bubble[2], merge[2], quick[2],
                bubble[3], merge[3], quick[3],
                bubble[4], merge[4], quick[4]);
    }

    fclose(resultado);

    printf("\nExperimento finalizado!\n");

    return 0;
}