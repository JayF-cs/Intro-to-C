#include <stdio.h>

void addingdigits();
void evenOrOdd();

int main(){

    evenOrOdd();
    return 0;
}

void addingdigits(){

    int userNum, temp, total = 0;
    printf("Enter a 4 digit number: ");
    scanf("%d",&userNum);
    temp = userNum % 10;
    userNum /= 10;
    total += temp;
    temp = userNum %10;
    userNum /= 10;
    total += temp;
    temp = userNum % 10;
    userNum /= 10;
    total += (temp + userNum);
    printf("Total is: %d", total);
    return;
}

void evenOrOdd(){

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num % 2){
        printf("%d is odd",num);
    }else{
        printf("%d is even", num);
    }
    return;
}