#include <stdio.h>

void printContem(float retA[4], float retB[4]){
    printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", retA[0], retA[1], retA[2], retA[3], retB[0], retB[1], retB[2], retB[3]);
}

int testRetangulo(float r1[4], float r2[4]){

    if(((r1[0] < r2[0]) && (r1[1] < r2[1])) && ((r1[2] > r2[2]) && (r1[3] > r2[3]))){
        printContem(r1, r2);
        
    } else if (((r1[0] > r2[0]) && (r1[1] > r2[1])) && ((r1[2] < r2[2]) && (r1[3] < r2[3]))){
        printContem(r2, r1);
        
    } else if((r2[0] + r2[1] + r2[2] + r2[3]) > 0){
        puts("Nao posso afirmar!");
    }
    
}


int main() {
    float ret1[4];
    float ret2[4];
    
    scanf("%f %f %f %f", &ret1[0], &ret1[1], &ret1[2], &ret1[3]);


    do {
        scanf("%f %f %f %f", &ret2[0], &ret2[1], &ret2[2], &ret2[3]);
        
        testRetangulo(ret1, ret2);
        
    } while ((ret2[3] != 0));

    return 0;
}
