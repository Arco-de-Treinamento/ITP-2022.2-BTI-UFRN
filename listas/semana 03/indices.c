#include <stdio.h>

int main() {
    int n, erro = 0, i = 0;
    float salto, salto_total = 0;

    scanf("%d", &n);

    do{
        scanf("%f", &salto);
        (salto != -1) ? salto_total = salto_total +  salto : erro++;

        i++;
    }while( i != n);
    
    if(n > 0){
    }

    if(salto_total > 0 && n >= 1) printf("%.2f", (salto_total/(n - erro)));
    else printf("A competicao nao possui dados historicos!");
    return 0;
}

