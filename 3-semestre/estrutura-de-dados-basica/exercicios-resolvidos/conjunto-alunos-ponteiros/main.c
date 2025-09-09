/*
PROBLEMA:
Implemente um programa em linguagem C para gerenciar um conjunto de alunos utilizando um vetor dinâmicom utilizando uma estrutura chamada Aluno com os seguintes campos: nome (string), matricula (inteiro) e nota1, nota2, nota3. Com as seguintes funcionalidades:
a) Inserir um novo aluno
    A função deve realocar memória automaticamente conforme necessário, aumentando a capacidade do vetor.
b) Buscar um aluno pela matrícula
    A função recebe o vetor de alunos e uma matrícula, e retorna o aluno ou uma indicação de que não foi encontrado.
c) Calcular a média das notas de um aluno
    A função recebe um aluno e retorna a média.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nome;
    int matricula;
    float nota1;
    float nota2;
    float nota3;
}Aluno;

Aluno *inserir_aluno(Aluno *lista_alunos, char *nome, int matricula, float nota1, float nota2, float nota3, int *quantidade_alunos_cadastrados){
    (*quantidade_alunos_cadastrados) ++;
    Aluno *novo_tamanho_lista = (Aluno *)realloc(lista_alunos,sizeof(Aluno) * (*quantidade_alunos_cadastrados));
    if(novo_tamanho_lista == NULL){
        free(lista_alunos);
        return NULL;
    }
    lista_alunos = novo_tamanho_lista;
    Aluno *novo_aluno = &lista_alunos[(*quantidade_alunos_cadastrados) - 1];
    novo_aluno->nome = (char *)malloc(strlen(nome) + 1);
    strcpy(novo_aluno->nome,nome);
    novo_aluno->matricula = matricula;
    novo_aluno->nota1 = nota1;
    novo_aluno->nota2 = nota2;
    novo_aluno->nota3 = nota3;
    return lista_alunos;
}

void imprimir_alunos(Aluno *lista_alunos, int quantidade_cadastrada){
    for(int i = 0; i < quantidade_cadastrada; i ++){
        printf("Matricula: %d\n",lista_alunos[i].matricula);
        printf("Nome: %s\n",lista_alunos[i].nome);
        printf("Nota 1: %.2f\n",lista_alunos[i].nota1);
        printf("Nota 2: %.2f\n",lista_alunos[i].nota2);
        printf("Nota 3: %.2f\n",lista_alunos[i].nota3);
    }
}

void buscar_matricula(Aluno *lista_alunos, int quantidade_cadastrada, int matricula_buscada){
    int encontrado = 0;
    for(int i = 0; i < quantidade_cadastrada; i ++){
        if(lista_alunos[i].matricula == matricula_buscada){
            encontrado = 1;
            printf("Nome: %s\n",lista_alunos[i].nome);
            printf("Nota 1: %.2f\n",lista_alunos[i].nota1);
            printf("Nota 2: %.2f\n",lista_alunos[i].nota2);
            printf("Nota 3: %.2f\n",lista_alunos[i].nota3);
        }
    }
    if(encontrado == 0){
        printf("Aluno não encontrado!\n");
    }
}

float calcular_media(Aluno *lista_alunos, int quantidade_cadastrada, int matricula_buscada){
    int encontrado = 0;
    for(int i = 0; i < quantidade_cadastrada; i ++){
        if(lista_alunos[i].matricula == matricula_buscada){
            encontrado = 1;
            return ((lista_alunos[i].nota1 + lista_alunos[i].nota2 + lista_alunos[i].nota3) / 3);
        }
    }
    if(encontrado == 0){
        return 0.0;
    }
}

int main(){
    Aluno *lista_alunos = NULL;
    int quantidade_cadastrada = 0;
    lista_alunos = inserir_aluno(lista_alunos,"Julio",1,10,2,3,&quantidade_cadastrada);
    buscar_matricula(lista_alunos,quantidade_cadastrada,1);
    float media;
    media = calcular_media(lista_alunos,quantidade_cadastrada,1);
    printf("Média: %.2f",media);



}
