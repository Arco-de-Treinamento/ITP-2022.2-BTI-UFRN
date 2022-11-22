// Codigo retirado do Video "ITP - Semana 08 - Promoção do Colégio" para fins de estudo.
// Link: https://www.youtube.com/watch?v=5augystBtb8
// Autor: Prof. André Brito

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct a{
    char nome[TAM];
    float nota;
} Aluno;

typedef struct t{
    Aluno p[TAM];
    int tam_turma;
    float media;
} Turma;

Turma leia_turma(){
    Turma nova;
    char entrada[TAM];
    nova.tam_turma = 0;

    scanf(" %[^\n]", entrada);

    while(strcmp(entrada, "*")){
        strcpy(nova.p[nova.tam_turma].nome, entrada);
        scanf("%f", &nova.p[nova.tam_turma].nota);
        nova.tam_turma++;

        scanf(" %[^\n]", entrada);   
    }

    return nova;
}

float calcula_media(Turma t){
    float media = 0;
    for(int i = 0; i < t.tam_turma; i++) media += t.p[i].nota;

    return media/t.tam_turma;
}

Aluno achar_melhor(Turma a, Turma b){
    Aluno best = {.nota = 0};

    for(int i = 0; i < a.tam_turma; i++)
        if(a.p[i].nota > best.nota) best = a.p[i];
    
    for(int i = 0; i < b.tam_turma; i++)
        if(b.p[i].nota > best.nota) best = b.p[i];
    
    return best;
}

int main(){
    Turma A, B;
    Aluno melhor;

    A = leia_turma();
    B = leia_turma();

    A.media = calcula_media(A);
    B.media = calcula_media(B);

    if(A.media > 8.0 && B.media > 8.0)
        puts("Viagem para todos!");
    else if(A.media > 8.0)
        puts("Viagem para turma A");
    else if(B.media > 8.0)
        puts("Viagem para turma B");
    else
        puts("Nenhuma das turmas viaja...");

    melhor = achar_melhor(A, B);

    if(melhor.nota > 8.0){
        printf("%s ganhou viagem e ingresso no parque!\n", melhor.nome);
        printf("Nota: %.2f\n", melhor.nota);
    }
    else
        puts("Ninguem ganhou viagem e ingresso no parque...");

    return 0;
}