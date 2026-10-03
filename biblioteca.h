#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float notas[3]; // Vetor de notas
    float media;    // Media das notas
} Aluno;

void CalculaMedia(Aluno alunos[] , int n);
int OrdenaAlunosDec(Aluno alunos[], int n); 
int OrdenarAlunos(Aluno alunos[], int n);
void merge(Aluno alunos[], int inicio, int meio, int fim, int *contador);
void mergeSort(Aluno alunos[], int inicio, int fim, int *contador);
int particiona(Aluno alunos[], int inicio, int fim, int *contador);
void quickSort(Aluno alunos[], int inicio, int fim, int *contador);

