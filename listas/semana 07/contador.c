#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toLowerString(char* string){
    for(int i = 0; i < strlen(string); i++) string[i] = tolower(string[i]);
}

int checkPadrao(int posi, char* stringComp, char* string){
    for(int i = 0; i < strlen(stringComp); i++){
        if(string[posi + i] != stringComp[i]) return 0;
    }
    return 1;
}

int main(){
    char stringComp[41], string[41];
    int cont = 0, pos[41] = {0};

    fgets(stringComp, 40, stdin);
    fgets(string, 40, stdin);

    stringComp[strlen(stringComp) - 1] = '\0';
    string[strlen(string) - 1] = '\0';
    toLowerString(stringComp);
    toLowerString(string);

    for(int i = 0; i <= (strlen(string) - strlen(stringComp)); i++){
        if(checkPadrao(i, stringComp, string) == 1){
            pos[cont] = i;
            cont++;
        }
    }

    printf("Repetições: %d\n", cont);

    if(cont > 0){
        printf("Posições:");

        for(int i = 0; i < cont; i++){
            printf(" %d", pos[i]);
        }
        puts("");
    }
    return 0;
}