#include <stdio.h>

/**
 * Realiza uma busca binária em um vetor ordenado
 * @param vetor[] Vetor ORDENADO onde será realizada a busca
 * @param tamanho Tamanho do vetor
 * @param valor Valor a ser buscado no vetor
 * @return Posição do valor no vetor se encontrado, -1 se não encontrado
 */
int busca_binaria_correta(int vetor[], int tamanho, int valor) {
    int inicio = 0;            // Índice inicial do segmento de busca
    int fim = tamanho - 1;     // Índice final do segmento de busca

    // Continua buscando enquanto o segmento for válido
    while (inicio <= fim) {
        // Calcula o ponto médio evitando possível overflow
        // Melhor que (inicio + fim) / 2 para números grandes
        int meio = inicio + (fim - inicio) / 2;

        // Caso 1: Valor encontrado exatamente na posição do meio
        if (valor == vetor[meio]) {
            return meio;  // Retorna a posição onde o valor foi encontrado
        }
        // Caso 2: O valor buscado é menor que o valor do meio
        // Busca na metade esquerda do segmento atual
        else if (valor < vetor[meio]) {
            fim = meio - 1;  // Ajusta o fim para buscar apenas a metade esquerda
        }
        // Caso 3: O valor buscado é maior que o valor do meio
        // Busca na metade direita do segmento atual
        else {
            inicio = meio + 1;  // Ajusta o início para buscar apenas a metade direita
        }
    }

    return -1;  // Valor não encontrado no vetor
}

/**
 * Função principal que demonstra o uso da busca binária
 */
int main() {
    // Vetor ORDENADO crescentemente (requisito essencial para busca binária)
    int vetor[] = {5, 10, 21, 21, 32, 54, 72, 76};

    // Calcula o tamanho do vetor dividindo o tamanho total pelo tamanho de um elemento
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Valor que se deseja buscar no vetor
    int valor = 21;

    // Chama a função de busca binária
    int posicao = busca_binaria_correta(vetor, tamanho, valor);

    // Exibe o resultado da busca
    if (posicao != -1) {
        printf("Valor %d encontrado na posição %d\n", valor, posicao);
    } else {
        printf("Valor %d não encontrado\n", valor);
    }

    return 0;  // Indica que o programa terminou com sucesso
}
