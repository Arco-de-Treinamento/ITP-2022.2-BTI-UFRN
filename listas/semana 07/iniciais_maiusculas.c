#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkInicio(char caractere){
    return (caractere == ' ') ? 1 : 0;
}

int main(){
    char frase[61];
    fgets(frase, 60, stdin);

    for(int i = 1; i < strlen(frase); i++){
        if(checkInicio(frase[i - 1])){
            frase[i] = toupper(frase[i]);
        } else {
            frase[i] = tolower(frase[i]);
        }
    }

    printf("%s", frase);
    return 0;
}