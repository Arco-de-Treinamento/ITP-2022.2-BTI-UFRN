#include <stdio.h>

int main() {
    int unid, soma_unid = 0;
    float valor, valor_total = 0;

    while(1){
        scanf("%d", &unid);

        if(unid >= 0){
            scanf("%f", &valor);
            soma_unid = soma_unid + unid;
            valor_total = valor_total + (unid * valor);
        }else{
            break;
        }
    }

    printf("%d %.2f", soma_unid, valor_total);
    return 0;
}

