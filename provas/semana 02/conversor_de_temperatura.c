#include <stdio.h>
#include <stdlib.h>

int main(){
    int temp;
    char scal;
    float tempCel, tempKel, tempFar;

    scanf("%d %c", &temp, &scal);

    switch (scal)
    {
    case 'C':
        tempCel = temp;
        tempFar = (temp * 1.8) + 32;
        tempKel = temp + 273.15;
        break;
    
    case 'F':
        tempCel = (temp - 32) / 1.8;
        tempFar = temp;
        tempKel = ((temp - 32) / 1.8) + 273.15;
        break;
    
    case 'K':
        tempCel = temp - 273.15;
        tempFar = ((temp - 273.15) * 1.8) + 32;
        tempKel = temp;
        break;

    default:
        break;
    }

    printf("Celsius: %.2f\n", tempCel);
    printf("Farenheit: %.2f\n", tempFar);
    printf("Kelvin: %.2f\n", tempKel);

    return 0;
}