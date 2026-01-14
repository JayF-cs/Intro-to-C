/*
James Fryar
August 25, 2025
This is for calculating the average of 5 scores
*/

#include <stdio.h>

int main()
{
    //Initialize float variables
    float score1, score2, score3, score4, score5;
    float avg, total;

    printf("Enter the scores for 5 subjects separated by space: "); //Prompt user for input

    scanf("%f %f %f %f %f", &score1, &score2, &score3, &score4, &score5); //Get user input

    total = score1 + score2 + score3 + score4 + score5; //Add all scores together and storing in total

    avg = total/5; //Get average by dividing by total number of scores

    printf("\nTotal score: %f", total); //Print total of scores
    printf("\nPercentage: %f %%", avg); //Print average of scores

    return 0;
}
