#include <stdio.h>
#include <stdlib.h>

int** alocMatriz(int x, int y){
    int** matriz = malloc (x * sizeof(int*));
    for(int r = 0; r < x; r++) matriz[r] = malloc (x * sizeof(int));
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if((i == 0) || (j == 0) || (i == (x - 1)) || (j == (y - 1))) matriz[i][j] = 0;
            else scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}

int checkBomba(int** matriz, int jediM, int jediN, int m, int n){
    int aux = 0, bCount = 0;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j <= n; j++){
            aux = 1;

            for(int k = i-1; k <= i+1; k++){
                for(int l = j-1; l <= j+1; l++){
                    if((k != i || l != j) && (matriz[i][j] <= matriz[k][l])) aux = 0;
                }
            }

            if(aux){
                printf("Local %d: %d %d\n", bCount + 1, i, j);
                bCount++;

                if(jediM == i && jediN == j) return 1;
            }
        }
    }

    return 0;
}

int main(){
    int n, m, jediN, jediM;

    scanf("%d %d", &m, &n);
    scanf("%d %d", &jediM, &jediN);

    int** map = alocMatriz((m + 2), (n + 2));

    if(checkBomba(map, jediM, jediN, m, n)){
        puts("Descanse na Força...");
    }else{
        puts("Ao resgate!");
    }

    return 0;
}