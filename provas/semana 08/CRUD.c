#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo;
} Pessoa;

Pessoa grupo[30];


Pessoa criar(char* nome, int idade, char sexo){
    Pessoa pessoa;
    strcpy(pessoa.nome, nome);
    pessoa.idade = idade;
    pessoa.sexo = sexo;

    return pessoa;
}

int inserir(Pessoa* pessoas, Pessoa novaPessoa, int qnt_pessoas){
    pessoas[qnt_pessoas] = novaPessoa;
    return qnt_pessoas + 1;
}


int deletar(Pessoa* pessoas, Pessoa excluida, int qnt_pessoas){    
    int aux = 0;
    for(int i = 0; i < (qnt_pessoas - 1); i++){
        if((strcmp(pessoas[i].nome, excluida.nome) == 0) &&
           (pessoas[i].idade == excluida.idade) &&
           (pessoas[i].sexo == excluida.sexo)
        ){ 
            // realoca os elementos
            for(int j = i; j < (qnt_pessoas - 1); j++) pessoas[j] = pessoas[j+1];
            return (qnt_pessoas - 1);
        }
    }
    return qnt_pessoas;
}


void imprimir(Pessoa* pessoas, int qnt_pessoas){
    for(int i = 0; i < qnt_pessoas; i++) 
        printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
}

Pessoa setPessoa(){
    char sexo;
    char nome[200];
    int idade;

    scanf(" %[^\n]s", nome);
    scanf(" %d %c", &idade, &sexo);

    return criar(nome, idade, sexo);
}

int main(){
    int qnt_pessoas = 0;
    char verif;
    
    scanf(" %c", &verif);
    
    while(verif != 'p'){
        switch (verif){
        case 'i':
            qnt_pessoas = inserir(grupo, setPessoa(), qnt_pessoas);
            break;
        
        case 'd':
            qnt_pessoas = deletar(grupo, setPessoa(), qnt_pessoas);
            break;

        default:
            puts("Operação inválida!");
            break;
        }

        scanf(" %c", &verif);
    };

    imprimir(grupo, qnt_pessoas);
    return 0;
}