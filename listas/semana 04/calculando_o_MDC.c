#include <stdio.h>

//Algoritmo de Euclides
int MDC(int x, int y){
    if(y > 0){
        return MDC(y, (x % y));
    }else{
        return x;
    }
} 


int main() {
    int x, y;
    scanf("%d %d", &x, &y);
     
    printf("MDC(%d , %d) = %d", x, y, MDC(x,y));
    
    return 0;
}

