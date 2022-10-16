// Solução preguiçosa
#include <stdio.h>

int main() {
    int n, aprov = 0, rec = 0, rep = 0;
    scanf("%d", &n);

    float aprovados[2][n];
    float reprovados[2][n];
    float recuperacao[2][n];

    for(int i = 0; i < n; i++){
        float nota;
        char ch;
        int num;

        scanf("%d %c %f", &num, &ch, &nota);

        if(nota >= 7.0){
            aprovados[0][aprov] = num;
            aprovados[1][aprov] = nota;
            aprov++;
        }else if(nota >= 5.0 && nota < 7.0){
            recuperacao[0][rec] = num;
            recuperacao[1][rec] = nota;
            rec++;
        }else{
            reprovados[0][rep] = num;
            reprovados[1][rep] = nota;
            rep++;
        }
    }


    printf("Aprovados: ");
    for(int i = 0; i < aprov; i++){
        printf("%d (%.1f)", (int)aprovados[0][i], aprovados[1][i]);
        if(i < aprov - 1) printf(", ");
    }
    puts("");

    printf("Recuperação: ");
    for(int i = 0; i < rec; i++){
        printf("%d (%.1f)", (int)recuperacao[0][i], recuperacao[1][i]);
        if(i < rec - 1) printf(", ");
    }
    puts("");

    printf("Reprovados: ");
    for(int i = 0; i < rep; i++){
        printf("%d (%.1f)", (int)reprovados[0][i], reprovados[1][i]);
        if(i < rep - 1) printf(", ");
    }
    puts("");

    return 0;
}

