#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float preco; 
    int quant;
} Item;

Item createItem(){
    Item item;
    
    scanf(" %[^\n]s", item.nome);
    scanf(" %f %d", &item.preco, &item.quant);

    return item;
}

Item* addItem(Item* itens, Item newItem, int *quantItens){
    if(*quantItens == 0) itens = malloc(sizeof(Item));
    else itens = realloc(itens, sizeof(Item) * (*quantItens + 1));

    itens[*quantItens] = newItem;
    
    (*quantItens)++;
    return itens;
}

void contBancariaKiller(Item *itens, int quantItens, int quantPessoas){
    float total = 0;

    for(int i= 0; i < quantItens; i++){
        total += (itens[i].preco * itens[i].quant);
    }

    printf("Valor: R$ %.2f\n", total);
    printf("Divisão R$ %.2f para cada participante.\n", (total/quantPessoas));
} 

int main(){
    Item *itens;
    int quantPessoas, verif = 1, quantItens = 0;
    

    while(verif != 2){
        itens = addItem(itens, createItem(), &quantItens);
        scanf(" %d", &verif);
    };

    scanf(" %d", &quantPessoas);

    contBancariaKiller(itens, quantItens, quantPessoas);

    free(itens);
    itens = NULL;
    return 0;
}
