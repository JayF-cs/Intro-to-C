#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));
    int centerX,centerY, radius, randX, randY, randDistance;
    printf("Enter the center of your circle and its radius (a b radius): ");
    scanf("%d %d %d",&centerX,&centerY,&radius);

    randX = 1 + rand() + centerX + radius + 3;
    randY = 1 + rand() + centerY + radius + 3;

    printf("The generated coordinate is: (%d,%d)", randX, randY);

    randDistance = sqrt(pow((centerX +randX),2)+pow((centerY +randY),2));

    if(randDistance > radius){
        printf("Point is inside the circle");
    }else{
        printf("Point is outside the circle");
    }

}