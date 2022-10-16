#include <stdio.h>

int main() {
    int N, C = 0, S = 0, L = 0;
    char prova;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        while(1){
            scanf("%c", &prova);
            if(prova == 'F') break;

            switch (prova)
            {
            case 'C':
                C++;
                break;
            
            case 'S':
                S++;
                break;
            
            case 'L':
                L++;
                break;
            }
        }
    }

    printf("%d %d %d %d", C, S, L, (C + S + L));

    return 0;
}