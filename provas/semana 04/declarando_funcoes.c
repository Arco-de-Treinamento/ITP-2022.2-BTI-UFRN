#include <stdio.h>
#include <stdbool.h>

char* ehPar(int n){
    return ((n% 2) == 0)? "true" : "false";
}



int main() {
    int num;
    scanf("%d", &num);

    printf("%s\n",ehPar(num));

    return 0;
}
