#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[200];
    int golsSofridos;
    int golsFeitos;
} Time;

Time setTime(){
    Time time;
    scanf(" %[^\n]", time.nome);
    scanf("%d %d", &time.golsFeitos, &time.golsSofridos);

    return time;
}

Time* ordenarTabela(Time *time, int size){ 
    Time aux; 

    for(int i = 0; i < size; i++){ 
        for(int j = 1; j < size; j++){
            if(time[j-1].golsFeitos < time[j].golsFeitos){ 
                aux = time[j-1]; 
                time[j-1] = time[j]; 
                time[j] = aux; 
            }
        }
    }     
    return time;
}

void printTimes(Time *time, int size){
    for(int i = 0; i < size; i++){
        printf("%d - %s\n", (i + 1), time[i].nome);
        printf("Gols marcados: %d\n", time[i].golsFeitos);
        printf("Gols sofridos: %d\n", time[i].golsSofridos);
    }
}

int main(){
    int T;
    scanf("%d", &T);

    Time time[T];
    for(int i = 0; i < T; i++) time[i] = setTime();

    printTimes(ordenarTabela(time, T), T);

    return 0;
}