#include <stdio.h>

int testa_divisor(int numero, int divisor){
    return ((numero % divisor) == 0) ? 1 : 0;
}

int soma_divisores(int value){
    int soma = 0;
    for(int i = 1; i < value; i++){      
        if(testa_divisor(value, i)) soma += i;
    }

    return soma;
}

int testa_amigos(int a, int b){
    int somaA = soma_divisores(a);
    int somaB = soma_divisores(b);

    return (((somaA == b) && (somaB == a)) && a != b) ? 1 : 0;
}


int main() {
    int L1[2], L2[2], amigos = 0;
    scanf("%d %d", &L1[0], &L1[1]);
    scanf("%d %d", &L2[0], &L2[1]);


    for(int a = L1[0]; a < L1[1]; a++){  
        for (int b = L2[0]; b < L2[1]; b++){
            if(testa_amigos(b, a)){
                printf("O %d possui um amigo!\n", a);
                amigos++;
            }
        }
    }

    if(amigos == 0) puts("Os intervalos nao apresentam amigos!");

    return 0;
}

