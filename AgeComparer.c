#include <stdio.h>

int main(){

    //Initialize age variables
    int age1, age2, age3;
    
    //Prompt users for inputs
    printf("Enter ages of three people (person1, person 2, and person 3): ");
    
    //Scan user inputs
    scanf("%d %d %d",&age1,&age2,&age3);

    //Compare age 1 to ages 2 and 3
    if(age1 < age2 && age1 < age3){
        //If 1 is less then 2 and 3 then 1 is youngest
        printf("\nPerson 1 is youngest");

    //Compare age 2 to ages 1 and 3
    }else if(age2 < age1 && age2 < age3){
        //If 2 is less then 1 and 3 then 2 is youngest
        printf("\nPerson 2 is youngest");

    //Compare age 3 to ages 1 and 2
    }else{
        //If 3 is less then 1 and 2 then 3 is the youngest
        printf("\nPerson 3 is youngest");
    }

    return 0;
}