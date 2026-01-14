#include <stdio.h>

int main(){

    //Declare variable
    int year;

    //Prompt user
    printf("Enter a year: ");
    //Take input
    scanf("%d",&year);

    //Check input against leap year rules
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        //Print if it is a leap year
        printf("%d is a leap year.",year);
    }
    else{
        //Print if it is not a leap year
        printf("%d is not a leap year.", year);
    }

    return 0;
}