#include <stdio.h>

float menorNota(float a, float b, float c){
    float notas[3] = {a, b, c};
    float aux = notas[0];
    for(int i = 0; i < 3; i++){
        if(notas[i] < aux) aux = notas[i];
    }

    return aux;
} 

float media5(float a, float b, float c){
    return ((a >= 3.0) && (b >= 3.0) && (c >= 3.0)) ? 1 : 0;
}


float provaFinal(float a, float b, float c){
    float soma = (a + b + c);
    float media =  soma/ 3;

    if(media5(a, b, c) && media < 5){
        return (15 - (soma - menorNota(a, b, c)));
    }else{
        return -1;
    }
}


int main() {
    float n1, n2, n3;
    scanf("%f %f %f", &n1, &n2, &n3);
    float final = provaFinal(n1, n2, n3);
     
    if (final > 1.0){
        puts("Final");
        printf("%.1f", final);

    }else puts("Nao faz prova final");
    
    return 0;
}

