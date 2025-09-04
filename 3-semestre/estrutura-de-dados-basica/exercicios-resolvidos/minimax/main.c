#include <stdio.h>

/*
PROBLEMA:
Implemente a função miniMax(v,n,a,b),
que recebe um vetor contendo n números e devolve em a e b,
respectivamente, os valores mínimo e máximo entre aqueles armazenados em v.

O objetivo é alterar os valores de a e b dentro de uma função usando ponteiros
pelo menor e maior valor no vetor


Função minimax tem como retorno void e precisa dos seguintes parâmetros:
-> vetor do tipo inteiro
-> tamanho do vetor
-> ponteiro que armazena o endereço da variável a
-> ponteiro que armazena o endereço da variável b
*/

void minimax(int vetor[], int tamanho_vetor, int *a, int *b){
    // Definindo as variáveis de maior e menor valor
    int maior_valor = vetor[0];
    int menor_valor = vetor[0];
    // Laço de repetição que percorre o vetor
    for(int i = 0; i < tamanho_vetor; i ++){
        if(vetor[i] > maior_valor){
            maior_valor = vetor[i];
        }
        if(vetor[i] < menor_valor){
            menor_valor = vetor[i];
        }
    }
    // A variável (a) que o ponteiro está armazenando o endereço, recebe o menor valor presente no vetor
    *a = menor_valor;
    // A variável (b) que o ponteiro está armazenando o endereço, recebe o maior valor presente no vetor
    *b = maior_valor;
}

int main(){

    // Definindo o vetor que vamos usar
    int vetor[] = {54,22,98,4,13,21,74,898,1};
    // Definindo o tamanho do vetor
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
    // Definindo as variáveis (a) e (b)
    int a = 0; // Inicializando (a) armazenando 0
    int b = 0; // Inicializando (b) armazenando 0
    // Chamando a função minimax e passando os parâmetros
    minimax(vetor,tamanho_vetor,&a,&b);
    // Conferindo os novos valores de (a) e (b)
    printf("Novo valor de (a): %d\nNovo valor de (b): %d",a,b);

    return 0;
}
