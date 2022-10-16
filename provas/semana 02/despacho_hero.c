#include <stdio.h>

int requerCareca(int qHero, int cHero, int cMonster){
    if(qHero < 1)
        return 1;
    else if((cMonster == 5 ) && (cHero < 5))
        return 1;
    else if((cHero > cMonster) || (cHero == 5))
        return 0;
    else if (cHero <= cMonster)
        return ((qHero * cHero) >= (3 * cMonster)) ? 0 : 1;
    else
        return 1;
}

int main(){
    int quantHero, classeHero, classeMonster;

    scanf("%d %d %d", &quantHero, &classeHero, &classeMonster);
    
    if(requerCareca(quantHero, classeHero, classeMonster) == 1)
        puts("Melhor chamar Saitama!");
    else
        puts("Heróis vencerão!");

    return 0;
}