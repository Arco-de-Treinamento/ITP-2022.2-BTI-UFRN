// Codigo retirado do Video "ITP - Semana 08 - Assuma o controle" para fins de estudo.
// Link: https://www.youtube.com/watch?v=IWJtNB94BPQ
// Autor: Prof. André Brito

#include <stdio.h>
#include <string.h>

#define TAM 100

typedef struct{
    char nomes[TAM][TAM];
    int tam;
} Lista;

int checa_pessoa(Lista t, char* str){
    for(int i = 0; i < t.tam; i++){
        if(strcmp(str, t.nomes[i]) == 0) return 1;
    }

    return 0;
}

Lista insere_pessoa(Lista t, char* str){
    if(checa_pessoa(t, str) == 0){
        strcpy(t.nomes[t.tam], str);
        t.tam++;
    }

    return t;
}

Lista remove_pessoa(Lista t, char* str){
    Lista novo;
    novo.tam = 0;

    if(checa_pessoa(t, str) == 1){
        for(int i = 0; i < t.tam; i++){
            if(strcmp(t.nomes[i], str) != 0){
                strcpy(novo.nomes[novo.tam], t.nomes[i]);
                novo.tam++;
            }
        }

        t = novo;
    }

    return t;
}

void imprime_pessoas(Lista t){
    printf("Atualmente trabalhando:\n");
    for(int i = 0; i < t.tam; i++) printf("%s\n", t.nomes[i]) ;
}

int main(){
    Lista ativos;
    char comando[TAM];
    char nome[TAM];
    int num_comandos;

    ativos.tam = 0;
    scanf("%d", &num_comandos);

    for(int i = 0; i < num_comandos; i++){
        scanf(" %s", comando);

        if(strcmp(comando, "INSERIR") == 0){
            scanf(" %s", nome);

            ativos = insere_pessoa(ativos, nome);
        }

        else if(strcmp(comando, "REMOVER") == 0){
            scanf(" %s", nome);

            ativos = remove_pessoa(ativos, nome);
        }
        else{
            imprime_pessoas(ativos);
            puts("");
        }
    }

    return 0;
}