/*
James Fryar
If-Else Problem 1: Profit or loss
9/4/25
*/

#include <stdio.h>

int main(){

    //Declare cost and sell price variables
    float costPrice, sellingPrice;

    //Prompt user for prices
    printf("Enter the cost price and selling price: ");
    //Take user input and store in price variables
    scanf("%f %f", &costPrice, &sellingPrice);

    //Check which price is greater than the other
    if(sellingPrice >costPrice){
        //If selling price greater display profit message and amount of profit
        printf("You made a profit.");
        printf("The amount of profit is $%f",sellingPrice-costPrice);

    }else if(sellingPrice < costPrice){
        //Else if cost price is graeter then display loss message and loss amount
        printf("You incurred loss.");
        printf("The amount of loss is $%f",costPrice-sellingPrice);
    }

}