#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contido(int n, int *array, int index){
    for(int i = 0; i < index; i++) if(array[i] == n) return 1;
    return 0;
}

int randomIndex(int* array, int size, int index){
    int sorteado = rand() % size;
    return (contido(sorteado, array, index)) ? randomIndex(array, size, index) : sorteado;
}

void sorteio(char** participantes, int size, int seed){
    int sorteados[size];
    int index;

    // Definindo a seed
    srand(seed);

    for(int i = 0; i < size; i++){
        sorteados[i] = randomIndex(sorteados,size, i);
    }

    for(int i; i < size; i++) printf("%s", participantes[sorteados[i]]);
}

char** salloc(char** matriz, int index){
    if(matriz == NULL) matriz = malloc(sizeof(char*));
    else matriz = realloc (matriz, sizeof(char*) * (index + 1));

    return matriz;
}

void saveString(char** matriz, int index, char string[]){
    if(matriz[index] == NULL){
        matriz[index] = malloc(sizeof(char) * (strlen(string) + 1));
        strcpy(matriz[index], "");

    }else{
        matriz[index] = realloc(matriz[index], sizeof(char) * (strlen(matriz[index]) + strlen(string) + 1));
    }

    strcat(matriz[index], string);
}

int main(){
    int index = 0, acabou = 0, allocNext = 1; 
    int size = 50;
    int seed;
    char string[size];
    char **participantes = NULL;

    // Leitura e armazenamento dos dados
    while(!acabou){
        fgets(string, size, stdin);

        if(strcmp(string, "acabou\n") != 0){
            if(allocNext == 1){
                participantes = salloc(participantes, index);
                participantes[index] = NULL;
                allocNext = 0;
            }

            saveString(participantes, index, string);

            if(string[strlen(string) -1] == '\n'){
                allocNext = 1;
                index++;
            }

        } else acabou = 1;
    }
    
    // Leitura da seed
    scanf("%d", &seed);

    // Iniciando sorteio
    sorteio(participantes, index, seed);

    // Limpando memoria
    for(int i = 0; i < index; i++) free(participantes[i]);
    free(participantes);

    return 0;
}