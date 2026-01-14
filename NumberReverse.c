/*
James Fryar
Number Reverser
08/30/25
*/

#include <stdio.h>

int main(){
    
    //Initialize variable for the user number, all digits, and total
    int userNum,total,firstDigit,secondDigit,thirdDigit,fourthDigit,fifthDigit,reversedNum;

    //Prompt users for numbers
    printf("Enter a five digit number: ");
    //Scan for user input
    scanf("%d", &userNum);

    //Get first digit using modulus 10
    firstDigit = userNum%10;
    //Get rid of far right digit
    userNum = userNum/10;

    //Get second digit using modulus 10
    secondDigit = userNum%10;
    //Remove far right digit
    userNum = userNum/10;
    
    //Get third digit using modulus 10
    thirdDigit = userNum%10;
    //Remove far right number
    userNum = userNum/10;
    
    //Get fourth digit
    fourthDigit = userNum%10;
    //Remove far right number
    userNum = userNum/10;

    //Get fifth digit, which now equalt the user number
    fifthDigit = userNum;

    //Add all digits together and assign it to total
    total = firstDigit + secondDigit + thirdDigit +fourthDigit + fifthDigit;

    //Get reverse number
    reversedNum = firstDigit*10000+secondDigit*1000+thirdDigit*100+fourthDigit*10+fifthDigit;

    //Print the reverse of the user's number
    printf("Reverse Number: %d", reversedNum);
    //Print the addition and the total of all the digits
    printf("\nSum of digits: %d + %d + %d + %d + %d = %d", fifthDigit,fourthDigit,thirdDigit,secondDigit,firstDigit, total);

    return 0;
}