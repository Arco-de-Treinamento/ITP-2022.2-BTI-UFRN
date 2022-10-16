#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char* string){
  int count = 0;
  while(string[count] != '\0') count++;

  return count;
}
char* subtString(char* stringA, char* stringB, char type){
    char* tempString;
    int aux = 0;

    switch (type){
    case 'p':
        for(int i = len(stringA); i < len(stringB); i++){
            tempString[aux] = stringB[i];
            aux++;
        }
        break;
    
    case 's':
        for(int i = 0; i < (len(stringB) - len(stringA)); i++){
            tempString[aux] = stringB[i];
            aux++;
        }
        break;

    default:
        break;
    }
    
    return tempString;
}

int contido(char* stringA, char* stringB, char type){
    int count = 0;

    for(int i = 0; i < len(stringA); i++){
        switch (type){
        case 'p':
            if(stringA[i] == stringB[i]) count++;
            break;
        
        case 's':
            if(stringA[i] == stringB[len(stringB) - len(stringA) + i]) count++;
            break;

        default:
            break;
        }
    }
    return (count == len(stringA)) ? 1 : 0;
}

int main() {
    int n, m, aux = 0;

    scanf("%d\n", &n);
    char prefixArray[n][10];
    if(n > 0){
        for(int i = 0; i < n; i++) scanf("%s", prefixArray[i]);
    }

    scanf("%d\n", &m);
    char sufixArray[m][10];
    if(m > 0){
        for(int i = 0; i < m; i++) scanf("%s", sufixArray[i]);
    }

    char palvArray[100][100];
    do{
        scanf("%s", palvArray[aux]);
        aux++;
        
    }while( strcmp(palvArray[aux-1], "-1") != 0);

    for(int i = 0; i < (aux - 1); i++){
        char* auxString = palvArray[i];
        
        for(int j = 0; j < n; j++){
            if(contido(prefixArray[j], auxString, 'p')){
                auxString = "";
                auxString = subtString(prefixArray[j], palvArray[i], 'p');
            }
        }

        for(int k = 0; k < m; k++){
            if(contido(sufixArray[k], auxString, 's')){
                auxString = "";
                auxString = subtString(sufixArray[k], palvArray[i], 's');
            }
        }

        printf("%s\n", auxString);
    }

    return 0;
}
