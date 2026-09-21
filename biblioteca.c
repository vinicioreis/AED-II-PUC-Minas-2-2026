#include "bibilioteca.h"

void DistribuiNotas(Aluno alunos[])
{
    int quantidadealunos = 5;
    for (int i = 0; i < quantidadealunos; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            alunos[i].notas[j] = (float)rand() / RAND_MAX * 10;
        }
    }
}

void CalculaMedia(Aluno alunos[])
{
    int quantidadealunos = 5;
    for (int i = 0; i < quantidadealunos; i++)
    {
        float soma = 0;
        for (int j = 0; j < 3; j++)
        {
            soma += alunos[i].notas[j];
        }
        alunos[i].media = soma / 3;
    }
}
void OrdenarAlunos(Aluno alunos[])
{
    int quantidaedealunos = 5;
    for (int i = 0; i < quantidaedealunos - 1; i++)
    {
        for (int j = 0; j < quantidaedealunos - 1 - i; j++)
        {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0)
            {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}
void OrdenaAlunosDec(Aluno alunos[])
{
    int quantidadealunos = 5;
    for (int i = 0; i < quantidadealunos - 1; i++)
    {
        for (int j = 0; j < quantidadealunos - 1 - i; j++)
        {
            if (alunos[j].media < alunos[j + 1].media)
            {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}
