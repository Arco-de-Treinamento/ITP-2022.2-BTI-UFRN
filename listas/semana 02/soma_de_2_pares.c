#include <stdio.h>

int main() {
    int A, B;

    scanf("%d %d", &A, &B);

    if(((A%2) == 0) && ((B%2) == 0)){
        printf("%d", (A+B));
    }

    if((A%2) > 0){
        printf("Não posso somar, pois %d não é par\n", A);
    }

    if((B%2) > 0){
        printf("Não posso somar, pois %d não é par\n", B);
    }

    return 0;
}