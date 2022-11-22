// Codigo retirado do Video "ITP - Semana 08 - IMD Cap" para fins de estudo.
// Link: https://www.youtube.com/watch?v=TJTdJhBUlLc
// Autor: Prof. André Brito

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id_cartela;
    int tam_cartela;
    int numeros[100];
    int marcacao[100];
} Cartela;

int checa_valor(int target, int tam, int* vet){
    for(int i = 0; i < tam; i++) if(target == vet[i]) return 1;
    return 0;
}

void inicializar_cartelas(int pos, Cartela* vet, int id, int tam_c, int tam_g){
    vet[pos].id_cartela = id;
    vet[pos].tam_cartela = 0;

    srand(id);

    for(int i = 0; i < tam_c; i++){
        int sorteado, ok;

        do{
            sorteado = rand()%tam_g + 1;
            ok = checa_valor(sorteado, vet[pos].tam_cartela, vet[pos].numeros);

        }while(ok);

        vet[pos].numeros[vet[pos].tam_cartela] = sorteado;
        vet[pos].tam_cartela++;
    }
}

int checa_marcacoes(int pos, Cartela* vet){
    for(int i = 0; i < vet[pos].tam_cartela; i++){
        if(vet[pos].marcacao[i] == 0) return 0;
    }

    return 1;
}

int marca_cartela(int pos, Cartela* vet, int valor){
    for(int i = 0; i < vet[pos].tam_cartela; i++){
        if(vet[pos].numeros[i] == valor) vet[pos].marcacao[i] = 1;
    }

    return checa_marcacoes(pos, vet);
}

int main(){
    int tam_cartela, range_globo, semente, tam = 0;
    char aux[30];
    Cartela jogos[30];


    scanf("%d %d %d", &tam_cartela, &range_globo, &semente);

    int sorteados[range_globo + 1];
    memset(jogos, 0, sizeof(jogos));
    memset(sorteados, 0, sizeof(sorteados));

    scanf(" %s", aux);

    while(strcmp(aux, "Comecou") != 0 ){
        int id;
        
        sscanf(aux, "%d", &id);

        inicializar_cartelas(tam, jogos, id, tam_cartela, range_globo);
        tam++;

        scanf(" %s", aux);
    }

    srand(semente);
    int fim_de_jogo = 0;
    
    while(!fim_de_jogo){
        int bola = rand()%range_globo + 1;

        if(sorteados[bola] == 1) continue;
        else{
            sorteados[bola] = 1;
            printf("%d ", bola);

            for(int i = 0; i < tam; i++){
                fim_de_jogo = marca_cartela(i, jogos, bola);

                if(fim_de_jogo){
                    printf("\nBingo! Cartela %d:", jogos[i].id_cartela);

                    for(int j = 0; j < jogos[i].tam_cartela; j++){
                        printf(" %d", jogos[i].numeros[j]);
                    }

                    puts("");
                    break;
                }
            }
        }
    }

    return 0;
}