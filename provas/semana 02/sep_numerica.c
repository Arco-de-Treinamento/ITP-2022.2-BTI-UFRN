#include <stdio.h>

int main(){
    int num, tempNum;
    char dig[6] = {'a','a','a','a','a','a'};

    scanf("%d", &num);
    sprintf(dig, "%d", num);

    for(int i = 0; i < 6; ++i){
        if(dig[i] != 'a'){
            tempNum = dig[i] - '0';
            if(tempNum >= 0)
                printf("%d\n", tempNum);
        }
    }

    return 0;
}