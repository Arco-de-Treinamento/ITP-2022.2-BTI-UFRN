#include <stdio.h>

int main() {
    int n, count = 1;

    scanf("%d", &n);
    if( n > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (i + 1); j++){
                (count < 10) ? printf(" %d ", count) : printf("%d ", count);
                count++;
            }
            puts("");
        }
    }else{
        printf("Você entrou com %d, tente de novo na próxima", n);
    }

    return 0;
}