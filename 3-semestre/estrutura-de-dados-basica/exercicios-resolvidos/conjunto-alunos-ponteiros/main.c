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

// Criação de uma struct denomidada "Aluno" com as seguintes variáveis: nome, matrícula, nota1, nota2 e nota 3
typedef struct {
    char *nome;
    int matricula;
    float nota1, nota2, nota3;
} Aluno;

// Criação da função que retorna um ponteiro p do tipo Aluno
Aluno *inserir_novo_aluno(char *nome, int matricula, float nota1, float nota2, float nota3) {
    // Realizando a alocação dinâmica da memória de acordo com a quantidade de alunos
    Aluno *p = (Aluno *)malloc(sizeof(Aluno));
    // Verificação se o ponteiro não é nulo
    if (p == NULL) {
        return NULL;
    }
    // Alocação dinâmica para o ponteiro responsável pelo nome
    p->nome = malloc(strlen(nome) + 1);
    // Copia o nome passado através dos parâmetros da função para a variável "nome" que o ponteiro está guardando o endereço
    strcpy(p->nome, nome);
    // Armazena a matricula
    p->matricula = matricula;
    // Armazena as três variáveis de nota do aluno
    p->nota1 = nota1;
    p->nota2 = nota2;
    p->nota3 = nota3;

    // Retorna o ponteiro p
    return p;
}

// Função responsável por buscar o aluno dentro de um vetor de alunos pela matricula
int buscar_aluno(Aluno *alunos[], int tamanho_vetor, int matricula) {
    // Laço de repetição que percorre o vetor
    for (int i = 0; i < tamanho_vetor; i++) {
        // Caso a matricula desejada seja encontrada no vetor, a função retorna 1
        if (alunos[i]->matricula == matricula) {
            return 1;
        }
    }
    // Caso a matricula não seja encontrada, a função retorna -1
    return -1;
}

// Função responsável por calcular a média do aluno
// O parâmetro é um ponteiro do tipo Aluno (struct)
float calcular_media(Aluno *aluno) {
    return (aluno->nota1 + aluno->nota2 + aluno->nota3) / 3.0;
}

int main() {
    // Criando um vetor de ponteiros do tipo Aluno com 5 posições
    Aluno *p[5];
    int i;

    // Inserindo alguns alunos para testar
    p[0] = inserir_novo_aluno("Julio", 101, 7.0, 8.0, 9.0);
    p[1] = inserir_novo_aluno("Carlos", 102, 6.0, 7.5, 8.0);
    p[2] = inserir_novo_aluno("Pedro", 103, 9.0, 9.5, 9.5);
    p[3] = inserir_novo_aluno("Pedro Henrique", 104, 5.0, 6.0, 7.0);
    p[4] = inserir_novo_aluno("Luca", 105, 8.0, 8.5, 9.0);

    // Testando a função de busca
    int matricula_buscada = 102;
    int verificar = buscar_aluno(p, 5, matricula_buscada);

    if (verificar == 1) {
        printf("Aluno com matricula %d foi encontrado.\n", matricula_buscada);
    } else {
        printf("Aluno com matricula %d nao foi encontrado.\n", matricula_buscada);
    }

    // Testando a função de média
    // Para calcular a média, você precisa de um ponteiro para o aluno, por isso acessamos p[0]
    float media = calcular_media(p[0]);
    printf("Media do aluno %s: %.2f\n", p[0]->nome, media);

    // Liberando a memória alocada para cada aluno
    for (i = 0; i < 5; i++) {
        free(p[i]->nome);
        free(p[i]);
    }

    return 0;
}
