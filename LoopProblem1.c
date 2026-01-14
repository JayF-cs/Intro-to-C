
#include <stdio.h>

//Define Tip Rate Constant
#define TIP_RATE 0.1

//Function Prototype
void printTipChart(int minVal, int maxVal);

int main( ){
    
    //Initialize Varibales
    int minVal, maxVal,numMenus=0;
    
    //Set up loop
    while(1){
        //Prompt User
        printf("Enter the minimum and maximum meal values: ");
        //Take inputs
        scanf("%d %d", &minVal, &maxVal);
        
        //Check if values are negative
        if(minVal <= 0 || maxVal <= 0){
            break;
        }
        
        //Call printTipChart function
        printTipChart(minVal,maxVal);

    //Increment number of menus only if a menu is printed i.e. min value is less than max value
    if(!(minVal > maxVal))
            numMenus++;
    }

    //Print number of menus that were printed
    printf("You have printed total %d valid charts", numMenus);


return 0;

}

void printTipChart(int minVal,  int maxVal){
    
    //Increment from minVal to maxVal and print the amount as well as the the recommended tip amount
    for(minVal; minVal <= maxVal; minVal++){
        printf("On a meal of $%d, the suggested tip amount $%.2f\n", minVal, (minVal*0.1));
    }
}
