#include <stdio.h>

char* ehPerfeito(int num){
    int soma = 0;
    for(int i = 1; i < num; i++){      
        if((num % i) == 0) soma += i;
    }
    
    return (soma == num) ? "eh" : "nao eh";
}



int main() {
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){  
        scanf("%d", &num);    
        printf("%d %s perfeito\n", num, ehPerfeito(num));
    }

    return 0;
}

