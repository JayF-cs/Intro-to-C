#include <stdio.h>
//Function Prototype
long long factorial(int x);
long long power(int x, int y);

int main() {
//Initialize Variables
int n;
double total=0;

//Prompt use and take input
printf("Enter your n:\n");
scanf("%d",&n);

//Iterate over the series
for(int i = 1; i <= n; i++){
    total += ((power(i,i)*1.0)/factorial(i));
}

//Print output
printf("Summation of the series from 1 to %d is: %.2lf",n,total);

    return 0;
}

long long factorial(int x){
    //Initialize base variable
    long long total = 1;
    //Iterate using for loop to get factorial
    for(int i = 1; i <= x; i++){
        total *= i;
    }
    
    return total;
}

long long power(int x, int y){
    //Initialize base
    long long power = 1;
    //Iterate over y using while loop to get exponent
    while(y>0){
        power *= x;
        y--;
    }
    
    return power;
}

