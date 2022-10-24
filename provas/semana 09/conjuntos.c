#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int* array;
} Conjunto;

int contido(int n, Conjunto *conjunto){
    for(int i = 0; i < conjunto->size; i++) if(conjunto->array[i] == n) return 1;
    return 0;
}

void printConjunto(Conjunto conjunto, char* operacao){
    printf("A %s B == {", operacao);

    if(conjunto.size > 0) {
        for(int i = 0; i < (conjunto.size - 1); i++) printf("%d ", conjunto.array[i]);
        printf("%d}\n", conjunto.array[conjunto.size - 1]);
    } 
    else printf("vazio}\n");
}

Conjunto uniao(Conjunto *A, Conjunto *B){
    Conjunto conjUniao;
    conjUniao.array = A->array;
    conjUniao.size = A->size;

    for (int i = 0; i < B->size; i++){
        if(!contido(B->array[i], A)){
            conjUniao.array[conjUniao.size] = B->array[i];
            conjUniao.size++;
        } 
    }
    return conjUniao;
}

Conjunto intersecao(Conjunto *A, Conjunto *B){
    Conjunto conjInter;
    conjInter.array = B->array;
    conjInter.size = 0;

    for (int i = 0; i < B->size; i++){
        if(contido(B->array[i], A)){
            conjInter.array[conjInter.size] = B->array[i];
            conjInter.size++;
        } 
    }

    return conjInter;
}

Conjunto setConjunto(){
    Conjunto conjunto;
    
    scanf("%d", &conjunto.size);
    conjunto.array = malloc(sizeof(int) * conjunto.size);
    for(int i = 0; i < conjunto.size; i++) scanf("%d", &conjunto.array[i]);

    return conjunto;
}

int main(){
    Conjunto A = setConjunto();
    Conjunto B = setConjunto();

    printConjunto(uniao(&A, &B), "união");
    printConjunto(intersecao(&A, &B), "interseção");

    return 0;
}