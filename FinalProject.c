#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leak_detector_c.h"

//Define Constants
#define FILE_NAME 30
#define MAX_STRING 50
#define MAX_SEMESTER 100

//Declare name char arrays for files
char studentFile[FILE_NAME + 1];
char courseFile[FILE_NAME + 1];
char EnrollFile[FILE_NAME + 1];

//Create date struct
typedef struct Date{
    int day;
    int month;
    int year;
} Date;

//Create student struct
typedef struct Student{

    int id;
    char *fName;
    char *lName;
    Date date;

} Student;

//Create course struct
typedef struct Course{

    char id[MAX_STRING + 1];
    char name[MAX_STRING + 1];
    float credit;

} Course;

//Create enrollment struct
typedef struct Enrollment{

    char cID[MAX_STRING + 1];
    int sID;
    char semester[MAX_STRING + 1];
    float score;

} Enrollment;

//Function prototypes
void find_students(Student *sArr, int numStudents, Enrollment *eArr, int numEnrollments, Course *cArr, int numCourses);
void find_course(Student *sArr, int numStudents, Enrollment *eArr, int numEnrollments, Course *cArr, int numCourses);
void add_course(Course **cArr, int *numCourses);
void total_command(Student *sArr, int numStudents, Enrollment *eArr, int numEnrollments, Course *cArr, int numCourses);
void sort_students(Student *sArr, int numStudents);
char get_letter_grade(float score);
void free_memory(Student *sArr,int numStudents, Enrollment *eArr, Course *cArr);
void menu(Student *sArr, int numStudents, Course *cArr, int numCourses, Enrollment *eArr, int numEnrollments);
Student* readStudents(int *numStudents);
Course* readCourses(int *numCourses);
Enrollment* readEnrollment(int *numEnrollment);


int main(){

    //For leak detector
    atexit(report_mem_leak);

    //Declare size variables for arrays
    int numStudents;
    int numCourses;
    int numEnrollments;

    //Get file names
    scanf("%s %s %s", studentFile,courseFile, EnrollFile);

    //Get DMA arrays
    Student *sArr = readStudents(&numStudents);
    Course *cArr = readCourses(&numCourses);
    Enrollment *eArr = readEnrollment(&numEnrollments);

    //Call menu function
    menu(sArr, numStudents,cArr,numCourses,eArr,numEnrollments);

    return 0;
}

//Read the student files
Student* readStudents(int *numStudents){
    
    //Create file pointer and open file
    FILE *sf;
    sf = fopen(studentFile, "r");

    //Make sure file pointer not null
    if(!sf){

        printf("Error opening file %s\n", studentFile);
        return NULL;
        
    }

    //Read and allocate space for student array
    fscanf(sf, "%d", numStudents); //Read number of students from file
    Student *sArr = (Student*)malloc((*numStudents)*sizeof(Student));
    for(int i = 0; i < (*numStudents); i++){
        
        //Create temperary strings for first and last name
        char tempF[MAX_STRING+1];
        char tempL[MAX_STRING +1];

        //Get first line of file data
        fscanf(sf,"%d %s %s %d %d %d", &sArr[i].id, tempF, tempL, &sArr[i].date.day, &sArr[i].date.month, &sArr[i].date.year);
        
        //Create DMA arrays for first and last names
        sArr[i].fName = malloc(strlen(tempF) + 1);
        strcpy(sArr[i].fName,tempF);
        sArr[i].lName = malloc(strlen(tempL) + 1);
        strcpy(sArr[i].lName,tempL);
    }

    //Close file pointer return DMA student array
    fclose(sf);
    return sArr;

}

//Read the course file
Course* readCourses(int *numCourses){
    
    //Create file pointer and open file
    FILE *cf;
    cf = fopen(courseFile, "r");
    
    //Make sure pointer exists
    if(!cf){

        printf("Error opening file %s\n", studentFile);
        return NULL;

    }

    //Read number of course from file
    fscanf(cf, "%d", numCourses); 
    
    //Create DMA for cours array
    Course *cArr = (Course*)malloc((*numCourses)*sizeof(Course));
    
    //Input data into array
    for(int i = 0; i < (*numCourses); i++){
        fscanf(cf,"%s %s %f", cArr[i].id, cArr[i].name, &cArr[i].credit);
    }

    //Close file pointer and return DMA pointer
    fclose(cf);
    return cArr;
}

//Read the enrollment file
Enrollment* readEnrollment(int *numEnrollment){

    //Create file pointer and open file
    FILE *ef;
    ef = fopen(EnrollFile, "r");

    //Make sure file exists
    if(!ef){

        printf("Error opening file %s\n", studentFile);
        return NULL;

    }

    //Read number of enrollments from file
    fscanf(ef, "%d", numEnrollment); 

    //Create DMA array for enrollments
    Enrollment *eArr = (Enrollment*)malloc((*numEnrollment)*sizeof(Enrollment));

    //Fill array
    for(int i = 0; i < (*numEnrollment); i++){
        fscanf(ef,"%s %d %s %f", eArr[i].cID, &eArr[i].sID, eArr[i].semester, &eArr[i].score);
    }

    //Close array and return DMA pointer
    fclose(ef);
    return eArr;
}

void menu(Student *sArr, int numStudents, Course *cArr, int numCourses, Enrollment *eArr, int numEnrollments){

    //Declare command array
    char command[MAX_STRING + 1];

    //Make sure pointers exist
    if(!sArr || !cArr || !eArr){
        printf("Error reading one or more files. Exiting.\n");
        return 0;
    }

    //Create menu loop
    while(1){

        //Get the user command
        scanf("%s", command);

        //Check which command it matches,
        if(strcmp(command,"find_students") == 0){
            
            find_students(sArr, numStudents, eArr, numEnrollments, cArr, numCourses);
        
        }else if(strcmp(command, "find_course") == 0){

            find_course(sArr, numStudents, eArr, numEnrollments, cArr, numCourses);

        }else if(strcmp(command,"add_course") == 0){
            
            //Create file pointer
            FILE *cf;

            //Call add course to get new DMA array with new course
            add_course(&cArr, &numCourses);
            
            //Open the file in write
            cf = fopen(courseFile, "w");

            //Check if file exists
            if (cf != NULL) { 
                fprintf(cf, "%d\n", numCourses);
                
                //Write the entirity of new array to file
                for(int i = 0; i < numCourses; i++){
                    fprintf(cf, "%s %s %.0f\n", cArr[i].id, cArr[i].name, cArr[i].credit); 
                } 
            
            }

            //Close file
            fclose(cf);

        }else if(strcmp(command, "total") == 0){

            total_command(sArr, numStudents,eArr, numEnrollments, cArr, numCourses);
            
        }else if(strcmp(command, "sort") == 0){
            
            sort_students(sArr, numStudents);

        }else if(strcmp(command, "exit") == 0){
            
            //If command is exit then print thank you message and call free memory function to free all memory
            printf("==================\n");
            printf("------------------\nThank you!\n");
            free_memory(sArr,numStudents,eArr,cArr);
            break;
        }
    }

}

char get_letter_grade(float score){

    //Return letter grade based on scores range
    if(score >= 90)
        return 'A';
    else if(score >= 80)
        return 'B';
    else if(score >= 70)
        return 'C';
    else if(score >= 60)
        return 'D';
    else
        return 'F';

}

void free_memory(Student *sArr,int numStudents, Enrollment *eArr, Course *cArr){
    //First iterate through sArr to free all the first and last name DMA arrays
    for(int i = 0; i < numStudents; i++){
        free(sArr[i].fName);
        free(sArr[i].lName);
    }

    //Then free all arrays with file data
    free(sArr);
    free(eArr);
    free(cArr);

}

void find_students(Student *sArr, int numStudents, Enrollment *eArr, int numEnrollments, Course *cArr, int numCourses){
    
    //Declare char arrays for option and key
    char option[MAX_STRING + 1], key[MAX_STRING + 1];

    //Declare found variable
    int found = 0;

    //Scan for option
    scanf("%s", option);
    printf("==================\n");
    printf("------------------\n");

    //Check if option is last name get the key
    if(strcmp(option, "lname") == 0){

        //Get the last name they are searching for
        scanf("%s", key);

        //Iterate through sArr
        for(int i = 0; i < numStudents; i++){
            
            //Check if key matches lname print that student
            if(strcmp(key,sArr[i].lName) == 0){
                printf("%d %s %s %d/%d/%d\n", sArr[i].id,sArr[i].fName,sArr[i].lName,sArr[i].date.month,sArr[i].date.day,sArr[i].date.year);
                
                //Iterate through eArr to get course ID of the student
                for(int j = 0; j < numEnrollments; j++){
                    if(eArr[j].sID == sArr[i].id){
                        printf("%s ", eArr[j].cID);
                        
                        //Iterate through cArr to find course name that matches the previously found course id and print it
                        for(int k = 0; k < numCourses; k++){
                            if(strcmp(eArr[j].cID, cArr[k].id) == 0){
                                printf("%s ", cArr[k].name);
                                break;
                            }
                        }
                        
                        //Print semester score and letter grade of the same enrollment for that cID/sId
                        printf("%s %.0f %c\n", eArr[j].semester, eArr[j].score, get_letter_grade(eArr[j].score));

                    }
                }

                printf("------------------\n");

                //Update found
                found = 1;
            }
        }

        //If found is zero print not found
        if(!found){
            printf("not found\n");
            printf("------------------\n");
        }
    }
    else if(strcmp(option,"id") == 0){ //Check if the option is id
        int studentID;
        //Get Id the are looking for
        scanf("%d",&studentID);

        //Iterate through sArr
        for(int i = 0; i < numStudents; i++){
            
            //Look for matching ID
            if(studentID == sArr[i].id){
                
                //Print student info if ID matches key
                printf("%d %s %s %d/%d/%d\n", sArr[i].id,sArr[i].fName,sArr[i].lName,sArr[i].date.month,sArr[i].date.day,sArr[i].date.year);
                
                //Iterate through enrollment to find matching sID
                for(int j = 0; j < numEnrollments; j++){
                    if(eArr[j].sID == sArr[i].id){
                        //Print the course number of mathcing ID
                        printf("%s ", eArr[j].cID);
                        
                        //Iterate through cArr to find course that matches course ID and print rest of course info
                        for(int k = 0; k < numCourses; k++){
                            if(strcmp(eArr[j].cID, cArr[k].id) == 0){
                                printf("%s ", cArr[k].name);
                                break;
                            }
                        }

                        //Print semester grade and letter grade from enrollment
                        printf("%s %.0f %c\n", eArr[j].semester, eArr[j].score, get_letter_grade(eArr[j].score));
                    }
                }
                printf("------------------\n");
                //Update found
                found = 1;
            }
        }

        //If found isn't updated then print not found
        if(!found){
            printf("not found\n");
            printf("------------------\n");
        }

    }


}

void find_course(Student *sArr, int numStudents, Enrollment *eArr, int numEnrollments, Course *cArr, int numCourses){
    
    //Declare char arrays for option and key
    char option[MAX_STRING + 1], key[MAX_STRING + 1];

    //Declare and initialize found var
    int found = 0;

    //Take input for option
    scanf("%s", option);
    printf("==================\n");
    printf("------------------\n");

    //Check if the inputed cid
    if(strcmp(option, "cid") == 0){
        
        //Take input for key
        scanf("%s", key);

        //Iterate through cArr
        for(int i = 0; i < numCourses; i++){
            //Look for matching course ID
            if(strcmp(key, cArr[i].id) == 0){
                //Print course info
                printf("%s %.0f\n", cArr[i].name,cArr[i].credit);
                
                //Iterate thoguh eArr to find matchin course IDs
                for(int j = 0; j < numEnrollments; j++){
                    if(strcmp(cArr[i].id, eArr[j].cID) == 0){
                        
                        //Iterate through sArr to find students who are enrolled in the course and print their info
                        for(int k = 0; k < numStudents; k++){
                            if(eArr[j].sID == sArr[k].id){

                                printf("%s %s %s %.0f %c\n", sArr[k].fName, sArr[k].lName, eArr[j].semester, eArr[j].score, get_letter_grade(eArr[j].score));
                            }
                        }
                    }
                }
                //update found
                found = 1;
                printf("------------------\n");
            }
        }
        //print if found not updated
        if(!found){
            printf("not found\n");
            printf("------------------\n");
        }
    }
    else if(strcmp(option,"cid_semester") == 0){ //Check if option is cid_semester

        //Create a semester string
        char semester[MAX_STRING + 1];

        //Get the course ID and the semester
        scanf("%s %s", key, semester);

        //Iterate through cArr
        for(int i = 0; i < numCourses; i++){
            //Look for matching course ID and print info
            if(strcmp(key, cArr[i].id) == 0){
                printf("%s %.0f\n", cArr[i].name,cArr[i].credit);
                
                //Iterate through eArr to find matching cID and semester
                for(int j = 0; j < numEnrollments; j++){
                    if(strcmp(cArr[i].id, eArr[j].cID) == 0 && strcmp(semester,eArr[j].semester) == 0){

                        //Look for student with matching sID and print info
                        for(int k = 0; k < numStudents; k++){
                            if(eArr[j].sID == sArr[k].id){

                                printf("%s %s %s %.0f %c\n", sArr[k].fName, sArr[k].lName, eArr[j].semester, eArr[j].score, get_letter_grade(eArr[j].score));
                            }
                        }
                    }
                }
                //update found
                found = 1;
                printf("------------------\n");
            }
        }
        //Print if found not updated
        if(!found){
            printf("not found\n");
            printf("------------------\n");
        }
    }
}

void add_course(Course **cArr, int *numCourses){
    //Declare char arrays for course ID and course name
    char cID[MAX_STRING + 1], courseName[MAX_STRING + 1];
    //credit var
    float credit;

    //Take input for course info
    scanf("%s %s %f", cID, courseName, &credit);
    printf("==================\n");
    printf("------------------\n");

    //Iterate through and make sure the provided id is unique
    for(int i = 0; i < *numCourses; i++){
        if(strcmp((*cArr)[i].id, cID) == 0){
            printf("\"new course id is not unique. Cannot add this course.\"\n");
            printf("------------------\n");
            return;

        }
    }
    
    //If it is unique update numcourse value
    (*numCourses)++; //dereference first the increment

    //Use realloc to increase DMA array size
    *cArr = (Course*)realloc(*cArr,((*numCourses) * sizeof(Course)));

    //Create course object and fill in info
    Course c;
    strcpy(c.id, cID);
    strcpy(c.name,courseName);
    c.credit = credit;

    //Add that struct object to array
    (*cArr)[*numCourses - 1] = c; //Dereference object point and then put c and the end position
    printf("record added\n");
    printf("------------------\n");
        
}

void total_command(Student *sArr, int numStudents, Enrollment *eArr, int numEnrollments, Course *cArr, int numCourses) {
    //Declare option array and take input for it 
    char option[MAX_STRING + 1];
    scanf("%s", option);
    
    printf("==================\n");
    printf("------------------\n");

    //Check if option is students and if is print numStudents
    if (strcmp(option, "students") == 0) {
        printf("%d\n", numStudents);
        printf("------------------\n");

    } else if (strcmp(option, "students_course") == 0) { //Check if option is students_course
        
        //Iterate through cArr
        for(int i = 0; i < numCourses;i++){
            //Create a count var
            int count = 0;

            //Iterate through eArr
            for(int j = 0; j < numEnrollments; j++){

                //Check if the course ID matches in cArr and eArr
                if(strcmp(cArr[i].id,eArr[j].cID) == 0){
                    //If it do increment count
                    count++;
                }
            }
            
            //Print the info for the course id
            printf("%s %d\n",cArr[i].id,count);
        
        }

        printf("------------------\n");

    }else if(strcmp(option,"students_semester") == 0){ // Check if option is students_semester
        //Create array of string to store semesters in
        char semester_tracker[MAX_SEMESTER][MAX_STRING+1];
        //Create an array to store num of students for each semester
        int student[MAX_SEMESTER];
        //Create len var to track len of semester_tracker array
        int len = 0;

        //Iterate through eArr
        for(int i = 0; i < numEnrollments; i++){
            
            //Declare and initialize exist var
            int exist = 0;

            //Iterate through semster tracker over its length
            for(int j = 0; j < len; j++){

                //Check if the semseter on that enrollment object exist int semster tracker each iteration
                if(strcmp(eArr[i].semester,semester_tracker[j]) == 0){
                    exist = 1; // If it do update exist var and break out of inner loop
                    break;
                }
                    
            }

            //If exist wasn't update add the semseter to semester tracker and increment len
            if(!exist){
                strcpy(semester_tracker[len],eArr[i].semester);
                len++;
            }
        }
            //iterate through semester_tracker
            for(int i = 0; i < len; i++){
                //Create count var
                int count = 0;
                
                //Iterate through eArr
                for(int j = 0; j < numEnrollments; j++){
                    
                    //Check if the semster tracker is same as the enrollment semester at that index
                    if(strcmp(semester_tracker[i], eArr[j].semester) == 0){
                        count++; //If it do then increment count
                    }
                }

                //Print the semester and count
                printf("%s %d\n", semester_tracker[i], count);
            }

        printf("------------------\n");      
        
    }
}

void sort_students(Student *sArr, int numStudents){
    
    //Bubble sort students based on ID number
    for(int i = 0; i < numStudents -1; i++){
        for(int j = 0; j < numStudents - i - 1; j++){
            if (sArr[j].id > sArr[j + 1].id) {
                // Swap students
                Student temp = sArr[j];
                sArr[j] = sArr[j + 1];
                sArr[j + 1] = temp;
            }
        }
    }

    printf("==================\n");
    printf("------------------\n");
    //Iterate through students and print the info for each
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %s %d/%d/%d\n", sArr[i].id, sArr[i].fName, sArr[i].lName, sArr[i].date.month, sArr[i].date.day, sArr[i].date.year);
    }
    printf("------------------\n");
}