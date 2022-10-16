#include <stdio.h>

int isPrimo(int num){
    for(int i = 2; i < num; i++){
        if(((num % i) == 0)) return 0;
    }

    return 1;
}


int main() {
    int n;
    scanf("%d", &n);

    if(isPrimo(n) && isPrimo(n + 2) && n > 1) printf("Numero forma par de gemeos");
    else printf("Numero nao forma par de gemeos");

    return 0;
}

