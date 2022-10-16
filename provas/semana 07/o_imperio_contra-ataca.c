#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

char KP[] = "QUE A FORCA ESTEJA COM VOCE";


void printCode(char* frase, int size){
  // Ocorrencia de estouro no Lop, gerando caracteres invalidos,
  // apesar de no replit e em minha maquina funcionar corretamente.
  // essa funcao limpa a sujeira. 
  
  for(int i = 0; i < size; i++){
    printf("%c", frase[i]);
  }
}

int indexChar(char element, char* S){
  for(int i = 0; i < strlen(S); i++) if(S[i] == element) return i;
}

void printArray(int* array, int size){
  for(int i = 0; i < size; i++) printf("%d", array[i]);
}

int compArray(int* array, int size){
  int count = 0;
  for(int i = 0; i < (size / 2); i++) if(array[i] == array[i + (size / 2)]) count++;
  
  return (count == (size / 2)) ? 1 : 0;
}

void cifra(int key[4], char* frase, char* S) {
  int teste, aux = 0;
  char fraseCifra[200];

  printArray(key, 4);
  puts("");

  for(int i = 0; i < (strlen(frase) - 1); i++){
    if(aux == 4) aux = 0;
    
    if((indexChar(frase[i], S) - key[aux]) >= 0) fraseCifra[i] = S[indexChar(frase[i], S) - key[aux]];
    else fraseCifra[i] = S[(strlen(S) + (indexChar(frase[i], S) - key[aux]))];

    aux++;
  }
  printCode(fraseCifra, (strlen(frase) - 1));
}

int* calcKey(char* frase, char* KP, char* S){
  int keyIndex;
  int pseudoKey[8], key[4];

  for(int i = 0; i < (strlen(frase) - strlen(KP)); i++){
    for(int j = 0; j < 8; j++){
      if((indexChar(frase[i + j], S) - indexChar(KP[j], S)) >= 0){
        pseudoKey[j] = indexChar(frase[i + j], S) - indexChar(KP[j], S);
      }else{
        pseudoKey[j] = 40 + (indexChar(frase[i + j], S) - indexChar(KP[j], S));
      }
    }

    if(compArray(pseudoKey, 8)){
      keyIndex = 4 - (i % 4);
      break;
    }
  }
  for(int k = 0; k < 4; k++) key[k] = pseudoKey[keyIndex + k]; 

  return (keyIndex > 0) ? key : NULL;
}


int main() {
  char frase[200];
  fgets(frase, 200, stdin);

  int* key = calcKey(frase, KP, S);

  if(key != NULL){
    cifra(key, frase, S);

  }else puts("Mensagem nao e da Resistencia!");

  return 0;
}
