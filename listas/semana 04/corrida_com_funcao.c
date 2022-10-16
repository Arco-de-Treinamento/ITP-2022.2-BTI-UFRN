#include <stdio.h>

int calcInstante(int dist, int vel1, int vel2){
    return dist / (vel1 - vel2);
}


int main() {
    int x, v1, v2;
    scanf("%d %d %d", &x, &v1, &v2);

    int tempo = calcInstante(x, v1, v2);

    if(tempo >= 0) printf("%ds", tempo);
    else puts("impossivel");
    
    return 0;
}

