#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[200];
    int pontos;
    int nPartidas;
    int vitorias;
    int empates;
    int derrotas;
    int golsFeitos;
    int golsSofridos;
    int saldoGols;
} Time;

Time setTime(){
    Time time;
    char data[200];
    char* pedaco;
    char* pedacos[6];

    scanf(" %[^\n]", data);
    pedaco = strtok(data, ";");

    for(int i = 0; pedaco != NULL; i++){
        pedacos[i] = pedaco;
        pedaco = strtok(NULL, " ");
    }
    
    strcpy(time.nome, pedacos[0]);
    time.vitorias = atoi(pedacos[1]);
    time.empates = atoi(pedacos[2]);
    time.derrotas = atoi(pedacos[3]);
    time.golsFeitos = atoi(pedacos[4]);
    time.golsSofridos = atoi(pedacos[5]);
    time.pontos = (time.vitorias * 3) + (time.empates * 1);
    time.saldoGols = time.golsFeitos - time.golsSofridos;
    time.nPartidas = time.vitorias + time.empates + time.derrotas;

    return time;
}

Time* ordenarTabela(Time *time, int size){ 
    Time aux; 


    for(int i = 0; i < size; i++){ 
        for(int j = 1; j < size; j++){
            // Classificação por pontos
            if(time[j-1].pontos < time[j].pontos){ 
                aux = time[j-1]; 
                time[j-1] = time[j]; 
                time[j] = aux; 
            } 

            // Classificação por vitoria
            if((time[j-1].pontos == time[j].pontos) && (time[j-1].vitorias < time[j].vitorias)){       
                aux = time[j-1]; 
                time[j-1] = time[j]; 
                time[j] = aux; 
            } 
            

            // Classificação por gols
            if((time[j-1].vitorias == time[j].vitorias) && (time[j-1].pontos == time[j].pontos) && (time[j-1].saldoGols < time[j].saldoGols)){
                aux = time[j-1]; 
                time[j-1] = time[j]; 
                time[j] = aux; 
            } 
        } 
    }
    return time;
}

void printTabela(Time *time, int size){
    puts("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols");

    for(int i = 0; i < size; i++){
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d \n", 
            time[i].nome, 
            time[i].pontos,
            time[i].nPartidas, 
            time[i].vitorias, 
            time[i].empates, 
            time[i].derrotas, 
            time[i].golsFeitos, 
            time[i].golsSofridos, 
            time[i].saldoGols
        );
    }

}

void printLibertadores(Time *time){
    puts("Times na zona da libertadores:");
    for(int i = 0; i < 6; i++) printf("%s\n", time[i].nome);
}

void printRebaixado(Time *time, int size){
    puts("Times rebaixados:");
    for(int i = (size - 1); i > (size - 5); i--) printf("%s\n", time[i].nome);
}

int main(){
    int T;
    scanf("%d", &T);

    Time time[T];
    for(int i = 0; i < T; i++) time[i] = setTime();

    puts("Tabela do campeonato:");
    printTabela(ordenarTabela(time, T), T);
    puts("");
    printLibertadores(ordenarTabela(time, T));
    puts("");
    printRebaixado(ordenarTabela(time, T), T);

    return 0;
}