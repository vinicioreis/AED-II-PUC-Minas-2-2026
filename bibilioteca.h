#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float notas[5]; // Vetor de notas
    float media;    // Média das notas
} Aluno;

void DistribuiNotas(Aluno alunos[]);
void CalculaMedia(Aluno alunos[]);
void OrdenaAlunosDec(Aluno alunos[]);
void OrdenarAlunos(Aluno alunos[]);