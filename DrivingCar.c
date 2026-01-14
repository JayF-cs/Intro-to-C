#include <stdio.h>

void drive(double *pOdom, double *pFeul, double mpg, double distance);

int main(){

    double odometer, *pOdom = &odometer;
    double fuel, *pFeul = &fuel;
    double mpg;
    double distance;

    printf("Enter odometer reading, fuel gauge reading and mpg: ");
    scanf("%lf %lf %lf", &odometer, &fuel, &mpg);

    while(fuel > 0){
        printf("Enter the distance you want to drive: ");
        scanf("%lf", &distance);
        drive(pOdom, pFeul, mpg, distance);
        printf("Current reading odometer = %.2lf, fuel = %.2lf\n", odometer, fuel);
    }

    printf("No more fuel!");

}

void drive(double *pOdom, double *pFeul, double mpg, double distance){

    if(distance > *pFeul*(mpg)){
        *pOdom += *pFeul*(mpg);
        *pFeul = 0;

    }else{
        *pOdom += distance;
        *pFeul -= (distance/(mpg));
    }
}