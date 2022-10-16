// o 1° e o 3° teste realmente estao com a saida esperada correta?
// seguindo a logica da otimização, nao faz sentido lê o caractere anterior
// se já sabemos que ele nao condiz coom o que estamos procurando.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scanPadrao(char* texto, char* padrao){
    int aux, salto = 0, index = -1;

    for(int i = 0; i < strlen(texto); i++){
        aux = 0;

        for(int j = 0; j < strlen(padrao); j++){
            printf("%c ", texto[i + j]);
            
            if(padrao[j] == texto[i + j]) aux++;

            else{
                i = j + i;
                break;
            }
        }

        if (aux == strlen(padrao)){
            puts("sim");
            index = i;
            break;
        } else puts("não");
    };

    return index;
} 

int main() {
    char padrao[50];
    char texto[50];

    scanf("%s", texto);
    scanf("%s", padrao);

    int index = scanPadrao(texto, padrao);

    if(index >= 0) printf("Achei o padrão no índice %d", index);
    else puts("Não achei o padrão");

    return 0;
}
