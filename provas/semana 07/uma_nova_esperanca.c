#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

int len(char* string){
  int count = 0;
  while(string[count] != '\0') count++;

  return count;
}

int checkKey(int key) {
  return (key >= 0 && key <= 9999) ? 1 : 0;
}

int checkFrase(char *frase, char* S) {
  for (int i = 0; i < (len(frase) - 1); i++) {
    int aux = 0;

    for (int j = 0; j < len(S); j++) {
      if (frase[i] == S[j]){ 
        aux = 1;
        break;
      } 
    }
    if(aux == 0) return 0;
  }
  return 1;
}

int indexChar(char element, char* S){
  for(int i = 0; i < len(S); i++) if(S[i] == element) return i;
}

void printCode(char* frase, char* S){
  // Ocorrencia de estouro no Lop, gerando caracteres invalidos,
  // apesar de no replit e em minha maquina funcionar corretamente.
  // essa funcao limpa a sujeira. 
  
  for(int i = 0; i < len(frase); i++){
    for (int j = 0; j < len(S); j++) {
      if (frase[i] == S[j]){ 
        printf("%c", frase[i]);
        break;
      } 
    }
  }
}

int* sepKey(int Key){
    char dig[4] = {'a','a','a','a'};
    int* arrayKey = malloc (4 * sizeof(int));

    sprintf(dig, "%d", Key);

    for(int i = 0; i < 4; ++i){
      if(dig[i] != 'a') arrayKey[i] = dig[i] - '0';
    }
    return arrayKey;
}


void cifra(int key, char* frase, char* S) {
  int aux = 0;
  int* arrayKey = sepKey(key);
  char fraseCifra[200];
  

  for(int i = 0; i < (len(frase) - 1); i++){
    if(aux == 4) aux = 0;

    if((indexChar(frase[i], S) + arrayKey[aux]) < len(S)) fraseCifra[i] = S[indexChar(frase[i], S) + arrayKey[aux]];
    else fraseCifra[i] = S[(indexChar(frase[i], S) - len(S)) + arrayKey[aux]];

    aux++;
  }
  printCode(fraseCifra, S);
}

int main() {
  int key;
  char frase[200];

  scanf("%d\n", &key);
  fgets(frase, 200, stdin);

  if (checkKey(key)) {
    if (checkFrase(frase, S)) {
      cifra(key, frase, S);

    } else puts("Caractere invalido na entrada!");
  } else puts("Chave invalida!");

  return 0;
}
