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

typedef struct {
    char *nome;
    int matricula;
    float nota1, nota2, nota3;
} Aluno;

// Função para inserir aluno no vetor (realoca automaticamente)
Aluno* inserir_aluno(Aluno *alunos, int *tamanho, int *capacidade,
                    char *nome, int matricula, float nota1, float nota2, float nota3) {

    // Verifica se precisa aumentar o vetor
    if (*tamanho >= *capacidade) {
        *capacidade += 2; // Aumenta a capacidade em 2
        alunos = (Aluno*)realloc(alunos, (*capacidade) * sizeof(Aluno));

        if (alunos == NULL) {
            printf("Erro ao realocar memória!\n");
            return NULL;
        }
        printf("Vetor aumentado para %d posições\n", *capacidade);
    }

    // Aloca memória para o nome
    alunos[*tamanho].nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    if (alunos[*tamanho].nome == NULL) {
        printf("Erro ao alocar memória para nome!\n");
        return alunos;
    }

    // Copia o nome
    strcpy(alunos[*tamanho].nome, nome);

    // Preenche os demais campos
    alunos[*tamanho].matricula = matricula;
    alunos[*tamanho].nota1 = nota1;
    alunos[*tamanho].nota2 = nota2;
    alunos[*tamanho].nota3 = nota3;

    (*tamanho)++; // Incrementa o tamanho atual
    return alunos;
}

// Função para buscar aluno por matrícula
Aluno* buscar_aluno(Aluno *alunos, int tamanho, int matricula) {
    for (int i = 0; i < tamanho; i++) {
        if (alunos[i].matricula == matricula) {
            return &alunos[i]; // Retorna o endereço do aluno encontrado
        }
    }
    return NULL; // Retorna NULL se não encontrou
}

// Função para calcular a média de um aluno
float calcular_media(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0f;
}

// Função para liberar toda a memória alocada
void liberar_memoria(Aluno *alunos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(alunos[i].nome); // Libera a memória do nome
    }
    free(alunos); // Libera o vetor de alunos
    printf("Memória liberada com sucesso!\n");
}

// Função para exibir todos os alunos
void exibir_alunos(Aluno *alunos, int tamanho) {
    printf("\n=== LISTA DE ALUNOS ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Nome: %s\n", alunos[i].nome);
        printf("  Matrícula: %d\n", alunos[i].matricula);
        printf("  Notas: %.1f, %.1f, %.1f\n", alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);
        printf("  Média: %.2f\n\n", calcular_media(alunos[i]));
    }
}

int main() {
    int capacidade = 2;  // Capacidade inicial do vetor
    int tamanho = 0;     // Número atual de alunos no vetor
    Aluno *alunos = NULL; // Vetor de alunos

    // Aloca memória inicial
    alunos = (Aluno*)malloc(capacidade * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória inicial!\n");
        return 1;
    }

    printf("=== SISTEMA DE GERENCIAMENTO DE ALUNOS ===\n");

    // Inserindo alunos (o vetor aumentará automaticamente)
    alunos = inserir_aluno(alunos, &tamanho, &capacidade, "João Silva", 1001, 8.5, 7.0, 9.0);
    alunos = inserir_aluno(alunos, &tamanho, &capacidade, "Maria Santos", 1002, 9.0, 8.5, 7.5);
    alunos = inserir_aluno(alunos, &tamanho, &capacidade, "Pedro Costa", 1003, 6.5, 7.0, 8.0);
    alunos = inserir_aluno(alunos, &tamanho, &capacidade, "Ana Oliveira", 1004, 10.0, 9.5, 9.0);

    // Exibe todos os alunos
    exibir_alunos(alunos, tamanho);

    // Busca por matrícula existente
    printf("=== BUSCA POR MATRÍCULA ===\n");
    Aluno *aluno_encontrado = buscar_aluno(alunos, tamanho, 1002);
    if (aluno_encontrado != NULL) {
        printf("Aluno encontrado:\n");
        printf("  Nome: %s\n", aluno_encontrado->nome);
        printf("  Média: %.2f\n", calcular_media(*aluno_encontrado));
    } else {
        printf("Matrícula não encontrada!\n");
    }

    // Busca por matrícula inexistente
    aluno_encontrado = buscar_aluno(alunos, tamanho, 9999);
    if (aluno_encontrado != NULL) {
        printf("Aluno encontrado: %s\n", aluno_encontrado->nome);
    } else {
        printf("Matrícula 9999 não encontrada!\n");
    }

    // Libera toda a memória alocada
    liberar_memoria(alunos, tamanho);

    return 0;
}
