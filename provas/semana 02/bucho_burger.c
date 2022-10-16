#include <stdio.h>
int caixa(int val, int pag){
    if(val == pag)
        puts("Deu certim!");
    else if(pag > val)
        printf("Troco = %d reais", (pag - val));
    else
        printf("Saldo insuficiente! Falta %d reais", (val - pag));
}

int main(){
    int nCombo, pagmento;

    scanf("%d %d", &nCombo, &pagmento);

    switch (nCombo)
    {
    case 1:
        caixa(12, pagmento);
        break;
    
    case 2:
        caixa(23, pagmento);
        break;
    
    case 3:
        caixa(31, pagmento);  
        break;

    case 4:
        caixa(28, pagmento);  
        break;

    case 5:
        caixa(15, pagmento);  
        break;
    default:
        puts("UEPA!");
        break;
    }

    return 0;
}