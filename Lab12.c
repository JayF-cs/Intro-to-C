#include <stdio.h>
#include <string.h>

#define MAX_ID 21
#define SIZE_EMP 100
#define SIZE_DEP 50
#define MAX_NAME 101
#define MAXFILELEN 50

typedef struct Employee{

    char id[MAX_ID];
    char lName[MAX_NAME];
    int salary;

} Employee;

typedef struct Dept{

    char id[MAX_ID];
    char deptName[MAX_NAME];

}Dept;
    

int readEmp(Employee ArrayOfEmployees[], char empFileName[]);
void readDept(Dept ArrayOfDepartments[], int *numOfDept, char deptFileName[]);
void printAll(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept);
void search_employee(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[]);
int totalSal_dept(Employee Arr[], int totalEmp,Dept ArrayOfDepartments[], int totalDept, char qStr[]);


int main(){

    char empFile[MAXFILELEN], deptFile[MAXFILELEN], queryFile[MAXFILELEN];
    scanf("%s %s %s", empFile, deptFile, queryFile);

    Employee empList[SIZE_EMP];
    Dept deptList[SIZE_DEP];

    int numEmp = readEmp(empList, empFile);
    int numDept;
    readDept(deptList, &numDept, deptFile);
    printAll(empList, numEmp, deptList, numDept);
    
    printf("Query Phase\n");

    FILE *qf = fopen(queryFile, "r");
    if (!qf) {
        printf("Cannot open query file.\n");
        return 0;
    }

    int n;
    fscanf(qf, "%d", &n);

    for(int i = 0; i < n; i++){
        int type;
        char key[MAX_NAME];
        fscanf(qf, "%d %s", &type, key);

        if(type == 1){
            search_employee(empList, numEmp, deptList, numDept, key);
        }else if(type == 2){
            int total = totalSal_dept(empList, numEmp, deptList, numDept, key);

        }
    }

    fclose(qf);
    return 0;

}

int readEmp(Employee arr[], char empFileName[]) {

    char eid[MAX_ID];
    char name[MAX_NAME];
    int sal;
    int count = 0;
    
    FILE *fp = fopen(empFileName, "r");
    if (!fp) {
        printf("Cannot open employee file.\n");
        return 0;
    }

    while(fscanf(fp,"%s %s %d", eid, name, &sal) != EOF){

        strcpy(arr[count].id, eid);
        strcpy(arr[count].lName, name);
        arr[count].salary = sal;

        count++;
    }

    fclose(fp);
    return count;
}

void readDept(Dept ArrayOfDepartments[], int *numOfDept, char deptFileName[]){

    char eid[MAX_ID];
    char deptName[MAX_NAME];
    int count = 0;

    FILE *fp = fopen(deptFileName, "r");
    if(!fp){
        printf("Cannot open department file.\n");
        return ;
    }

    while(fscanf(fp,"%s %s", eid, deptName) != EOF){

        strcpy(ArrayOfDepartments[count].id, eid);
        strcpy(ArrayOfDepartments[count].deptName, deptName);

        count++;
    }

    *numOfDept = count;
    fclose(fp);

}

void printAll(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept){
    char dept[MAX_NAME];

    printf("Printing the list of Employees:\n");
    printf("=================\n");

    for(int i = 0; i < totalEmp; i++){

         strcpy(dept, "None");

        for(int j = 0; j < totalDept; j++){
            if(strcmp(Arr[i].id,ArrayOfDepartments[j].id) == 0){
                strcpy(dept,ArrayOfDepartments[j].deptName);
                break;
            }
        }

         printf("ID: %s  LName: %s    Salary: %d     Department: %s\n", Arr[i].id, Arr[i].lName, Arr[i].salary,dept);

    }
}

void search_employee(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[]){
    char dept[MAX_NAME]; 
    
    for(int i = 0; i < totalEmp; i++ ){

        strcpy(dept, "None");

        for(int j = 0; j < totalDept; j++){
            if(strcmp(Arr[i].id,ArrayOfDepartments[j].id) == 0){
                strcpy(dept,ArrayOfDepartments[j].deptName);
                break;
            }
        }

        if(strcmp(Arr[i].lName, qStr) == 0){

            printf("ID: %s  LName: %s    Salary: %d     Department: %s\n", Arr[i].id, Arr[i].lName,Arr[i].salary,dept);
            return;

        }
     }

    printf("Employee %s Not Found\n", qStr);
}

int totalSal_dept(Employee Arr[], int totalEmp,Dept ArrayOfDepartments[], int totalDept, char qStr[]){

    int total = 0;

    for(int i = 0; i < totalDept; i++){
        
        if (strcmp(ArrayOfDepartments[i].deptName, qStr) == 0){

            for(int j = 0; j < totalEmp;j++){
                if(strcmp(ArrayOfDepartments[i].id,Arr[j].id)==0){
                    total += Arr[j].salary;
                }
            }
        }
    }
    
    printf("Total Salary of Department %s is %d\n", qStr, total);
    return total;
}