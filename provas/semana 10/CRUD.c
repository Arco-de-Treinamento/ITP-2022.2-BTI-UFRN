#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo;
} Pessoa;


void imprimir(Pessoa* pessoas, int qnt_pessoas){
    for(int i = 0; i < qnt_pessoas; i++) 
        printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
}

Pessoa criar(char* nome, int idade, char sexo){
    Pessoa pessoa;
    strcpy(pessoa.nome, nome);
    pessoa.idade = idade;
    pessoa.sexo = sexo;

    return pessoa;
}

Pessoa* inserir(Pessoa* pessoas, Pessoa novaPessoa, int *qnt_pessoas){    
    if(*qnt_pessoas == 0) pessoas = malloc(sizeof(Pessoa));
    else pessoas = realloc(pessoas, sizeof(Pessoa) * (*qnt_pessoas + 1));

    pessoas[*qnt_pessoas] = novaPessoa;

    (*qnt_pessoas)++;
    return pessoas;
}

Pessoa* deletar(Pessoa* pessoas, Pessoa excluida, int *qnt_pessoas){    
    for(int i = 0; i < (*qnt_pessoas - 1); i++){
        if((strcmp(pessoas[i].nome, excluida.nome) == 0) &&
           (pessoas[i].idade == excluida.idade) &&
           (pessoas[i].sexo == excluida.sexo)
        ){ 
            // realoca os elementos
            for(int j = i; j < (*qnt_pessoas - 1); j++) pessoas[j] = pessoas[j+1];
            pessoas = realloc(pessoas, sizeof(Pessoa) * (*qnt_pessoas + 1));
            (*qnt_pessoas)--;
        }
    }
    return pessoas;
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
    Pessoa *grupo;
    int qnt_pessoas = 0;
    char verif;
    
    scanf(" %c", &verif);
    
    while(verif != 'p'){
        switch (verif){
        case 'i':
            grupo = inserir(grupo, setPessoa(), &qnt_pessoas);
            break;
        
        case 'd':
            grupo = deletar(grupo, setPessoa(), &qnt_pessoas);
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