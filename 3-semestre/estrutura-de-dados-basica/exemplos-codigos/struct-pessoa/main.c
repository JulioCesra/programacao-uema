#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando uma struct denomidada "Pessoa" que tem como parâmetros: nome, idade.
typedef struct{
    char *nome;
    int idade;
}Pessoa;

// Criando uma função que vai retornar um ponteiro do tipo Pessoa.
Pessoa *criar_pessoa(char *nome, int idade){
    // Alocação dinâmica do ponteiro.
    Pessoa *nova_pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    // Verificando se o ponteiro é nulo.
    if(nova_pessoa == NULL){
        return NULL;
    }
    // Alocação dinâmica na quantidade de caracteres que um nome pode ter.
    nova_pessoa->nome = malloc(strlen(nome) + 1);
    // Copia o nome passado atráves dos parâmetros da função para o nome presente na struct.
    strcpy(nova_pessoa->nome,nome);
    nova_pessoa->idade = idade;

    return nova_pessoa;
}

int main(){

    // Criação de dois ponteiros do tipo Pessoa
    Pessoa *p1;
    Pessoa *p2;
    // Colocando informações atráves da função criar_pessoa
    p1 = criar_pessoa("Júlio",18);
    p2 = criar_pessoa("Pedro",19);
    // Verificando o funcionamento da função
    printf("INFORMAÇÕES DA PESSOA 1:\nNome: %s\nIdade: %d\n\n",p1->nome,p1->idade);
    printf("INFORMAÇÕES DA PESSOA 2:\nNome: %s\nIdade: %d\n",p2->nome,p2->idade);
    // Liberando a memória
    free(p1);
    free(p2);

    return 0;
}
