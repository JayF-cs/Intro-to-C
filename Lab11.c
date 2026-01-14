#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTD 100  //maximum number of students
#define MAXQZ 10 //maximum number of quizzes
#define MAXLEN 51  //maximum char array size. Max string length is 50.

 char getLetterGrade(float score);
 int getMaxTotalIdx(float totals[], int n);
 void writeData(FILE *out, char ids[][MAXLEN], char names[][MAXLEN],  float totals[], int n);
 int lookup(char names[][MAXLEN], char key[MAXLEN], int n);

int main()
{
    char ids[MAXSTD][MAXLEN]; //for string ids
    char names[MAXSTD][MAXLEN];// for storing last names
    float grades[MAXSTD][MAXQZ]; // for storing grades
    float totals[MAXSTD]; //for storing calculated totals

    char fileName[MAXLEN];

    fgets(fileName,MAXLEN,stdin);
    fileName[strcspn(fileName,"\n")] = '\0';


    //Create file pointers
    FILE *infile, *outfile;

    //Open read file
    infile = fopen(fileName,"r");
    //Make sure valid pointer
    if(!infile){
            printf("Error opening file.\n");
            return 1;
    }

    //Get number of students and grades
    int N,G;
    fscanf(infile, "%d %d", &N, &G);
    
    //Iterate through and get each students name and ID
    for(int i = 0; i < N; i++){
        //Scan from file
        fscanf(infile, "%s %s",ids[i],names[i]);
        //Iterate through and get all grades
        for(int j =0; j < G+2;j++){
            fscanf(infile,"%f", &grades[i][j]);
        }

        //Midterm at first index
        float midterm = grades[i][0];

        //Final at second index
        float final = grades[i][1];

        //Initialize sum of quizzes
        float quizSum = 0;

        //Start at index 2 and then add all quiz grades
        for(int k = 2; k < G + 2;k++){
            quizSum += grades[i][k];
        }

        //Get average of quizzes
        float quizAvg = quizSum/G;

        //Calculate totals for each student
        totals[i] = 0.35 * midterm + 0.40 *final + 0.25*quizAvg;
    }
    
    //Close file
    fclose(infile);

    //Open write file
    FILE *out = fopen("report.txt", "w");

    //Write the contents to the file
    writeData(out, ids, names, totals, N);

    //Close file 
    fclose(out);

    //Make key array
    char key[MAXLEN];
    //Prompt and take input
    printf("Enter a last name to search: ");
    fgets(key,MAXLEN,stdin);

    //Replace newline with null character
    key[strcspn(key,"\n")] = '\0';
    
    //Call lookup function
    int idx = lookup(names, key, N);

    //If idx if negative means was not found
    if (idx == -1) {
        printf("%s not found in the list.\n", key);
    } else {

        //else print the students details
        printf("%s was found in the list. Here is the details:\n", names[idx]);
        printf("ID: %s Lname: %s Total: %.2f\n", ids[idx], names[idx], totals[idx]);
        printf("Grades:\nMidterm: %.2f, Final term: %.2f, quizzes:\n",grades[idx][0], grades[idx][1]);

        for (int j = 2; j < G + 2; j++) {
            printf("%.2f ", grades[idx][j]);
        }
        printf("\n");
    }

}

char getLetterGrade(float score){
    //Check students score range
    if(score > 90){
        return 'A';
    }else if(score >= 80){
        return 'B';
    }else if(score >= 70){
        return 'C';
    }else{
        return 'F';
    }
}

int getMaxTotalIdx(float totals[], int n){
    //Iterate through and see which index hold max value
    int max = 0;
    for(int i = 1; i < n;i++){
        if(totals[i] > totals[max]){
            max = i;
        }
    }

    return max;
}

void writeData(FILE *out, char ids[][MAXLEN], char names[][MAXLEN],  float totals[], int n){
    
    //Print data and write to file
    printf("Summary of students:\n========\n");
    fprintf(out, "Summary of students:\n========\n");

    //Prints each student data and writes it to file
    for(int i = 0; i < n;i++){
        char lgrade = getLetterGrade(totals[i]);
        printf("ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i], totals[i], lgrade);
        fprintf(out, "ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i], totals[i], lgrade);
    }

    printf("\n========\n");
    fprintf(out, "\n========\n");

    int maxIndex = getMaxTotalIdx(totals,n);

    //Prints highest scoring student and data and writes it to file
    printf("First student with the highest total is %s %s %.2f\n",ids[maxIndex], names[maxIndex], totals[maxIndex]);
    fprintf(out, "First student with the highest total is %s %s %.2f\n",ids[maxIndex], names[maxIndex], totals[maxIndex]);

    printf("The summary is stored. Please check report.txt file.\n");

}

int lookup(char names[][MAXLEN], char key[MAXLEN], int n){
    for(int i = 0; i < n; i++){
        if(strcasecmp(names[i], key) == 0){
            return i;
        }
    }

    return -1;
}