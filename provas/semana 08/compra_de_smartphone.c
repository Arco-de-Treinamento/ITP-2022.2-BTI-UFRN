#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

Smartphone smartphones[20];


int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]){
    scanf(" %[^\n]s", phones[qnt_cadastrada].modelo);
    scanf(" %d %f %f %f", 
        &phones[qnt_cadastrada].memoria,
        &phones[qnt_cadastrada].processador,
        &phones[qnt_cadastrada].camera,
        &phones[qnt_cadastrada].bateria
    );

    return qnt_cadastrada + 1;
}

void printSmartphone(Smartphone smartphone){
    printf("Modelo: %s\n", smartphone.modelo);
    printf("Memoria: %dGB\n", smartphone.memoria);
    printf("Processador: %.2fGhz\n", smartphone.processador);
    printf("Camera: %.2fMPixels\n", smartphone.camera);
    printf("Bateria: %.2fmA\n", smartphone.bateria);
    puts("");
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin){
    int count = 0;

    for(int i = 0; i < qnt_cadastrada; i++){
        if((phones[i].memoria >= reqMin.memoria) &&
           (phones[i].processador >= reqMin.processador) &&
           (phones[i].camera >= reqMin.processador) &&
           (phones[i].bateria >= reqMin.bateria)
          ){
            printSmartphone(phones[i]);
            count++;
        }
    }
    return count;
}

int main(){
    char verif;
    Smartphone reqMin;
    int qnt_cadastrada = 0;
    
    // Atribuicao de dados
    scanf(" %c", &verif);

    do{
        qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, smartphones);
        scanf(" %c", &verif);

    }while(verif == 's');

    // Leitura do reqMin
    scanf(" %d %f %f %f", 
        &reqMin.memoria,
        &reqMin.processador,
        &reqMin.camera,
        &reqMin.bateria
    );

    // Pesquisa de dados
    int qnt_resultados = pesquisaSmartphones(qnt_cadastrada, smartphones, reqMin);
    printf("%d smartphones encontrados.", qnt_resultados);

    return 0;
}