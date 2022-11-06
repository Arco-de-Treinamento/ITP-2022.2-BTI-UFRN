#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* removeSpace(char* string){
    for(int i = 0; i < strlen(string); i++){
        if(isspace(string[i])){
            for(int j = 0; j < (strlen(string) - i); j++) string[i + j] = string[i + j + 1];
        } 
    }
    return string;
}

int isPalindromo(char* string, int first, int last){
    if(first >= last) return 1;
    else if(string[last] != string[first]) return 0;
    
    return isPalindromo(string, (first + 1), (last - 1));
}

int palindromo(char* entrada){
    char string[200];
    
    strcpy(string, entrada);
    removeSpace(string);

    return isPalindromo(string, 0, (strlen(string) - 1));
}

int main() {
    char frase[200];
    scanf(" %[^\n]", frase);

    printf("O texto \"%s\" %s palíndromo\n", frase, (palindromo(frase))? "é" : "não é");

    return 0;
}