#include <stdio.h>
#include <stdlib.h>

void decToBin(int num){
    if((num / 2) != 0) decToBin(num / 2);
    printf("%d", (num % 2));
}

int main() {
    int num;

    scanf("%d", &num);
    decToBin(num);

    return 0;
}