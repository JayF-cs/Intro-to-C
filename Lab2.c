#include <stdio.h>
#include <math.h>

int main(){

    char input;

    printf("Enter a character: ");
    scanf("%c", &input);

    if(((input > 'A') && (input < 'Z'))){
        printf("\n%c is a capital letter. The letter is %d in the alphabet",input,(input - 'A')+1);

    }else if((input >= 'a') && (input <= 'z')){
        printf("\n%c is a small case letter. The letter is %d in the alphabet",input,(input - 'a')+1);

    }else if(input >= '0' && (input <= '9')){
        printf("\n%c is a digit",input);
        printf("\nThe square root of %c is %.2f", input, sqrt(input - '0'));

    }else{
        printf("\n%c is a special symbol",input);
    }

    return 0;
}