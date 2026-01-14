#include <stdio.h>

int main(){

float tempF, tempC;
printf("Enter the temperature in Fahrenheit: ");
scanf("%f", &tempF);

tempC = (5.0/9)*(tempF-32.0);
printf("The temperature in Celsius is: %f",tempC);

return 0;

}