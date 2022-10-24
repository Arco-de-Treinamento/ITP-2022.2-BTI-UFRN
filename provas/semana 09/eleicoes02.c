#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int nChapa;
    int votos;
    char nome[50];
} Party;

float calcPercent(int num, int total){
    return (((float)num / total)*100);
}

Party setParty(){
    Party party;
    char data[200];

    scanf(" %[^\n]", data);

    party.nChapa = atoi(strtok(data, " "));
    strcpy(party.nome, strtok(NULL, " "));
    party.votos = 0;

    return party;
}

int compute_votes(int num_votes, int votes[num_votes], 
                   int num_parties, Party parties[num_votes], 
                   Party *most_voted, Party *second_most_voted){

    Party aux;
    int votos_validos = 0;
 
    // Contabiliza os votos
    for(int i = 0; i < num_votes; i++){
        for(int j = 0; j < num_parties; j++){
            if(votes[i] == parties[j].nChapa){
                parties[j].votos++;
                votos_validos++;
            }
        }
    } 

    // Ordena vetor
    for(int i = 0; i < num_parties; i++){ 
        for(int j = 1; j < num_parties; j++){
            if(parties[j - 1].votos < parties[j].votos){ 
                aux = parties[j - 1]; 
                parties[j - 1] = parties[j]; 
                parties[j] = aux; 
            } 
        } 
    }

    // Retorna 1 e 2 colocado
    *most_voted = parties[0];
    *second_most_voted = parties[1];

    return votos_validos;
}

void printParties(int num_votes, Party *most_voted, Party *second_voted){
    printf("VENCEDOR: %s (%d votos = %.2f%)\n", most_voted->nome, most_voted->votos, calcPercent(most_voted->votos, num_votes));
    printf("VICE: %s (%d votos = %.2f%)\n", second_voted->nome, second_voted->votos, calcPercent(second_voted->votos, num_votes));
}

int main(){
    int num_parties, num_votes;
    Party most_voted, second_most_voted;

    scanf("%d", &num_parties);
    Party parties[num_parties];
    for(int i = 0; i < num_parties; i++) parties[i] = setParty();

    scanf("%d", &num_votes);
    int votes[num_votes];
    for(int i = 0; i < num_votes; i++) scanf("%d", &votes[i]);
    
    int votos_validos = compute_votes(num_votes, votes, num_parties, parties, &most_voted, &second_most_voted);
    printParties(votos_validos, &most_voted, &second_most_voted);

    return 0;
}