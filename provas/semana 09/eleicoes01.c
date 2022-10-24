#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nChapa;
    int votos;
} Chapa;


void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted){
    Chapa chapas[10];
    Chapa aux; 

    // Inicializa as chapas
    for(int i = 0; i < 10;  i++){
        chapas[i].nChapa = (i + 1);
        chapas[i].votos = 0;
    }

    // Contabiliza os votos
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++) if(votes[i] == chapas[j].nChapa) chapas[j].votos++;
    }

    // Ordena vetor
    for(int i = 0; i < 10; i++){ 
        for(int j = 1; j < 10; j++){
            if(chapas[j - 1].votos < chapas[j].votos){ 
                aux = chapas[j - 1]; 
                chapas[j - 1] = chapas[j]; 
                chapas[j] = aux; 
            } 
        } 
    }

    *most_voted = chapas[0].nChapa;
    *second_most_voted = chapas[1].nChapa;
}

int main(){
    int n, ganhador, vice;
    scanf("%d", &n);

    int votes[n];
    for(int i = 0; i < n; i++) scanf("%d", &votes[i]);

    compute_votes(n, votes, &ganhador, &vice);
    printf("%d %d", ganhador, vice);

    return 0;
}