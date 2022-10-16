#include <stdio.h>
#include <math.h>

int main() {
    float num[10];
    float soma_arit, soma_harm, prod = 1.0;
    float erro_harm, erro_geom, med_arit, med_harm, med_geom, erro_med;


    for(int i = 0; i < 10; i++){
        scanf("%f", &num[i]);

        prod = prod * num[i];
        soma_arit = soma_arit + num[i];
        soma_harm = soma_harm + (1.0/num[i]);
    }

    med_arit = soma_arit/10;
    med_geom = pow(prod, 0.1);
    med_harm = 10/soma_harm;
    erro_geom = ((med_harm - med_arit) / med_arit);
    erro_harm = ((med_geom - med_arit) / med_arit);
    erro_med = (((erro_harm + erro_geom)/2) * 100);
    
    printf("Média aritmética é %.2f\n", med_arit);
    printf("Média harmônica é %.2f\n", med_harm);
    printf("Média geométrica é %.2f\n", med_geom);
    printf("Erro médio é %.2f %%\n", erro_med);
    return 0;
}


// Erro_harmônica= (média harmônica - média aritmética) / média aritmética

// Erro_geométrica= (média geométrica- média aritmética) / média aritmética

// Erro_médio= (Erro_harmônica + Erro_geométrica)/2