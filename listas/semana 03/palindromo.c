#include <stdio.h>

char* par_ou_impar(int n){
    return ((n% 2) == 0)? "par" : "impar";
}

char* palindromo(int n){
    int a = n, rev = 0;

    while (a != 0) {
    rev = (rev * 10) + (a % 10);  
    a = a / 10;                     
    }

    return (rev == n) ? "é" : "não é";
}

int main() {
    int num;
    scanf("%d", &num);

    printf("%d %s Palíndromo e %s\n", num, palindromo(num), par_ou_impar(num));

    return 0;
}
