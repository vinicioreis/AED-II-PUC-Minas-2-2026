#include "biblioteca.h"

void CalculaMedia(Aluno alunos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        float soma = 0;
        for (int j = 0; j < 3; j++)
        {
            soma += alunos[i].notas[j];
        }
        alunos[i].media = soma / 3;
    }
}
int OrdenarAlunos(Aluno alunos[], int n)
{
    int contador = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            contador++;
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0)
            {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    return contador;
}
int OrdenaAlunosDec(Aluno alunos[], int n)
{
    int contador = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            contador++;
            if (alunos[j].media > alunos[j + 1].media)
            {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    return contador;
}

void merge(Aluno alunos[], int inicio, int meio, int fim, int *contador)
{
    {
        int tamanho = fim - inicio + 1;
        Aluno *aux = malloc(tamanho * sizeof(Aluno));

        if (aux == NULL)
            return;

        int i = inicio;
        int j = meio + 1;
        int k = 0;

        while (i <= meio && j <= fim) //* enquanto as duas metades ainda têm alunos
        {
            (*contador)++;

            if (alunos[i].media <= alunos[j].media)
            {
                aux[k] = alunos[i];
                i++;
            }
            else
            {
                aux[k] = alunos[j];
                j++;
            }
            k++;
        }

        while (i <= meio)
        {
            aux[k] = alunos[i];
            i++;
            k++;
        }

        while (j <= fim)
        {
            aux[k] = alunos[j];
            j++;
            k++;
        }

        for (k = 0; k < tamanho; k++)
        {
            alunos[inicio + k] = aux[k];
        }

        free(aux);
    }
}

void mergeSort(Aluno alunos[], int inicio, int fim, int *contador)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(alunos, inicio, meio, contador);  // metade esquerda
        mergeSort(alunos, meio + 1, fim, contador); // metade direita
        merge(alunos, inicio, meio, fim, contador); // junta as duas
    }
}
int particiona(Aluno alunos[], int inicio, int fim, int *contador)
{
    float pivo = alunos[fim].media;
    int i = inicio - 1;
    Aluno temp;

    for (int j = inicio; j < fim; j++)
    {
        (*contador)++;

        if (alunos[j].media < pivo)
        {
            i++;
            temp = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = temp;
        }
    }

    temp = alunos[i + 1];
    alunos[i + 1] = alunos[fim];
    alunos[fim] = temp;

    return i + 1;
}

void quickSort(Aluno alunos[], int inicio, int fim, int *contador)
{
    {
        if (inicio < fim)
        {
            int p = particiona(alunos, inicio, fim, contador);

            quickSort(alunos, inicio, p - 1, contador); /* lado esquerdo do pivô */
            quickSort(alunos, p + 1, fim, contador);    /* lado direito do pivô */
        }
    }
}
