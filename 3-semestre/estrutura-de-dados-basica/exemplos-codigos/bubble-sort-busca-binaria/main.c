#include <stdio.h>

int *bubble_sort(int *vetor, int tamanho_vetor){
    int temp = 0;
    for(int i = 0; i < tamanho_vetor - 1; i ++){
        for(int j = 0; j < tamanho_vetor - i - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    return vetor;
}

int busca_binaria(int *vetor_ordenado,int tamanho_vetor, int valor_buscado){
    int inicio = 0;
    int fim = tamanho_vetor - 1;
    while(inicio <= fim){
        int meio = inicio + (fim - inicio) / 2;
        if(vetor_ordenado[meio] == valor_buscado){
            return meio;
        }else if(vetor_ordenado[meio] < valor_buscado){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
    }
    return -1;
}
int main(){
    int vetor[] = {11,4,76,9,12,1};
    int *vetor_ordenado = NULL;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    vetor_ordenado = bubble_sort(vetor,tamanho);
    int valor_busca = 76;
    int posicao_encontrado = busca_binaria(vetor_ordenado,tamanho,valor_busca);
    if(posicao_encontrado != -1){
        printf("O valor %d foi encontrado na posicao %d\n",valor_busca,posicao_encontrado);
    }else{
        printf("O valor não foi encontrado!");
    }
    return 0;
}
