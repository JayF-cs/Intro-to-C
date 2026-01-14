/*
James Fryar
If-Else problem 2: Same Line?
09/04/25
*/

#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.000001

int main(){

    //Intiate all variables as floats
    float x1,x2,x3,y1,y2,y3,slope1,slope2;

    //Prompt user for input for all point
    printf("Enter coordinates (x1, y1): ");
    scanf("%f %f", &x1,&y1);
    printf("\nEnter coordinates (x2, y2): ");
    scanf("%f %f", &x2,&y2);
    printf("\nEnter coordinates (x3, y3): ");
    scanf("%f %f", &x3,&y3);

    //Calculate the slope from point set one and two
    slope1 = (y2-y1)/(x2-x1);
    //Calculate slope from point set one and three
    slope2 = (y3-y1)/(x3-x1);

    //Check if the absolute value of the difference of the two slopes is under threshold
    //defined in the assignment instructions 
    if(fabs(slope2-slope1)<THRESHOLD)
        //If it is less then threshold print on straight line
        printf("\nThey fall on one straight line");
    else
        //If not print they are not on one straight line
        printf("\nThey do not fall on one straight line");

    return 0;
}