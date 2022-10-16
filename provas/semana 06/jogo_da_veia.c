#include <stdio.h>
#include <stdlib.h>

char** alocMatriz(int sizeR, int sizeC){
    char** matriz = malloc (sizeR * sizeof(char*));
    for(int r = 0; r < sizeR; r++) matriz[r] = malloc (sizeR * sizeof(char));

    for(int i = 0; i < sizeR; i++){
        for(int j = 0; j < sizeC; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    return matriz;
}

int lugarVago(char** matriz, int posX, int posY){
    if(matriz[posX][posY] == '.') return 1;
    return 0;
}

int vitoria(char** matriz, int posX, int posY, char element){
    int count = 0;

    //horizontal
    for(int i = 0; i < 3; i++){
        count = 1;
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] == element) count++;
        }

        if(count == 3) return 1;
    }

    //vertical
    for(int i = 0; i < 3; i++){
        count = 1;
        for(int j = 0; j < 3; j++){
            if(matriz[j][i] == element) count ++;
        }

        if(count == 3) return 1;
    }
    
    //diagonal 
    if(matriz[0][0] == element && matriz[1][1] == element && matriz[2][2] == element) return 1;
    if(matriz[0][2] == element && matriz[1][1] == element && matriz[2][0] == element) return 1;

    return 0;
}

void jogada(char** matriz, int posX, int posY, char element){
    if(lugarVago(matriz, posX, posY)){
        if(vitoria(matriz, posX, posY, element)){
            puts("Boa jogada, vai vencer!");
        }else{
            puts("Continua o jogo.");
        }
    }else{
        puts("Jogada inválida!");
    }

}

int main() {
    int n, posX, posY;
    char element;
    char** matriz = alocMatriz(3,3);
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d %d %c", &posX, &posY, &element);
        jogada(matriz, (posX - 1), (posY - 1), element);
    }
    
    return 0;
}

