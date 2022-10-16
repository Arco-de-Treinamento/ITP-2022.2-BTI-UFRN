#include <stdio.h>
#include <stdlib.h>

int** alocMatriz(int x, int y){
    int** matriz = malloc (x * sizeof(int*));
    for(int r = 0; r < x; r++) matriz[r] = malloc (x * sizeof(int));

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++) scanf("%d", &matriz[i][j]);
    }

    return matriz;
}

int modulo(int num){ return (num < 0) ? num * -1 : num; }

int* selectArea(int** matriz, int x, int y, int sobIndex){
    int sum, dif, memDif;
    int* cordPoint = malloc(3 * sizeof(int));

    for(int i = 1; i < y-1; i++){
        for(int j = 1; j < x-1; j++){
            sum = matriz[i-1][j-1] + matriz[i-1][j] + matriz[i-1][j+1] +
                  matriz[i][j-1]   + matriz[i][j]   + matriz[i][j+1] +
                  matriz[i+1][j-1] + matriz[i+1][j] + matriz[i+1][j+1];
            
            dif = modulo(sobIndex - sum);

            if(i == 1 && j == 1){
                memDif = dif;
                cordPoint[0] = i;
                cordPoint[1] = j;
            }

            else if(dif < memDif){
                memDif = dif;
                cordPoint[0] = i;
                cordPoint[1] = j;
            }
        }
    }

    cordPoint[2] = memDif;

    return cordPoint;
}

int main(){
    int n, m, sobIndex;

    scanf("%d %d %d", &n, &m, &sobIndex);

    int** recursos = alocMatriz(n, m);
    int* cordPoint = selectArea(recursos, n, m, sobIndex);

    printf("A melhor area para exploracao eh %d %d com valor %d", cordPoint[0], cordPoint[1], cordPoint[2]);

    return 0;
}