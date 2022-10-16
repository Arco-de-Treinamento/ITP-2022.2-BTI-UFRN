#include <stdio.h>

int main() {
    int n_atleta = 0, n_serie = 0;
    float temp_prova, temp_atleta;

    scanf("%f", &temp_prova);

    while(1){
        scanf("%f", &temp_atleta);

        if((temp_atleta <= temp_prova) && (temp_atleta != -1)) n_atleta++;
        if(temp_atleta == -1) break;
    }

    n_serie = (n_atleta/8) + ((n_atleta % 8 > 0) ? 1 : 0);
    printf("%d %d", n_atleta, n_serie);

    return 0;
}

