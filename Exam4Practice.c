#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main(){

    FILE *fp,*wr;
    int n;
    int option;
    char name[50];

    fp = fopen("students.txt","r");

    fscanf(fp,"%d",&n);

    Student *ptr = (Student*)calloc(n,sizeof(Student));

    for(int i = 0; i < n; i++){

        fscanf(fp,"%s %d %f",ptr[i].name,ptr[i].age,ptr[i].gpa);

    }

    fclose(fp);

    printf("What would you like to do\n1) Add student\n2)Search for student\n3)Display all student\n4)Save all records back to file\n6)Exit\n");
    scanf("%d",&option);

    if(option == 1){
        Student* temp = realloc(ptr,++n);
        temp = ptr;
        Student s;
        printf("Enter student last name: ");
        scanf("%49[^\n]s",&s.name);
        printf("Enter students age: ");
        scanf("%d",&s.age);
        printf("Enter student gpa: ");
        scanf("%f",&s.gpa);
        ptr[n-1] = s;
    }else if (option == 2){
        printf("Enter student last name: ");
        scanf("%49[^\n]s",name);
        for(int i = 0; i < n; i++){
            if(strcmp(ptr[i].name,name)){
                printf("Last Name: %s, Age: %d, GPA: %f", ptr[i].name, ptr[i].age,ptr[i].gpa);
                break;
            }
        }
    }else if(option == 3){
        for(int i = 0; i < n; i++){
                printf("Last Name: %s, Age: %d, GPA: %f\n", ptr[i].name, ptr[i].age,ptr[i].gpa);
        }
    }else if(option == 4){
        wr = fopen("students.txt", "w");
        fprintf(wr,"%d",n);
        for(int i = 0; i < n; i++){
            printf("%s %d %f\n", ptr[i].name, ptr[i].age,ptr[i].gpa);
        }

        fclose(wr);
        free(ptr);
    }
    


    return 0;

}