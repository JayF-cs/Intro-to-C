// Online C compiler to run C program online
#include <stdio.h>
float getScore();
char getLetterGrade(float score);
int main() {
    float numScore = getScore();
    char letterGrade = getLetterGrade(numScore);
    printf("You got %c",letterGrade);
    return 0;
}

float getScore(){
    float score1, score2, score3, finalScore;
    printf("Enter scores for exam1, exam2, and exam3: ");
    scanf("%d %d %d", &score1,&score2,&score3);
    score1 = score1 *0.2;
    score2 = score2 * 0.3;
    score3 = score3 * 0.5;
    finalScore = (score1+score2+score3)*100;
    return finalScore;
}

char getLetterGrade(float score){
    
    char grade;
    if(score >= 90){
        grade = 'A';
    }else if(score >= 80){
        grade = 'B';
    }else if(score >= 70){
        grade = 'C';
    }else if(score >= 60){
        grade = 'D';
    }else{
        grade = 'F';
    }
    
    return grade;
}