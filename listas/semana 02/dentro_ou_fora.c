#include <stdio.h>

int main() {
    int ret[4];
    int dot[2];

    scanf("%d %d %d %d", &ret[0], &ret[1], &ret[2], &ret[3]);
    scanf("%d %d", &dot[0], &dot[1]);

    if (((dot[0] >= ret[0]) && (dot[0] <= ret[2])) && ((dot[1] >= ret[1]) && (dot[1] <= ret[3]))){
        puts("Dentro!");
    }else{
        puts("Fora!");
    }

    return 0;
}