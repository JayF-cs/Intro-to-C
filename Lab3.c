#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Seed random
    srand(time(0));

    //Declare variables
    int centerX,centerY, radius, randX, randY;
    double randDistance;

    //Prompt user
    printf("Enter Center x,y coordinate and radius\n");

    //Take inputs
    scanf("%d %d",&centerX,&centerY);
    scanf("%d", &radius);

    //Generate random coordinates
    randX = 1 + rand() % (centerX + radius + 3);
    randY = 1 + rand() % (centerY + radius + 3);
    
    //Print random coordinates
    printf("The generated coordinate is: (%d,%d)\n", randX, randY);

    //Determine distance
    randDistance = sqrt(pow((randX - centerX),2)+pow((randY - centerY),2));

    //Determine if on circle
    if(randDistance == radius){
        printf("Point is on the circle");
    }
    //Determine if in circle
    else if(randDistance < radius){
        printf("Point is inside the circle");
    }
    //Determine outside of circle
    else{
        printf("Point is outside the circle");
    }

    return 0;
}