#include <stdio.h>
#define MAXROWS 100
#define MAXCOLUMNS 100
//Function prototypes
void displayMatrix(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols);
void findMaxPerRow(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols);
void printLLTriangle(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols);
void printURTriangle(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols);
void addMatrix(int matrix1[MAXROWS][MAXCOLUMNS],
               int matrix2[MAXROWS][MAXCOLUMNS],
               int result[MAXROWS][MAXCOLUMNS],
               int rows, int cols);
int sumSurrounding(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols, int i, int j);

int main(){

    //Declare variables and arrays
    int columns, rows;
    int matrix1[MAXROWS][MAXCOLUMNS];
    int matrix2[MAXROWS][MAXCOLUMNS];
    int results[MAXROWS][MAXCOLUMNS];
    int rowInput, columnInput;

    //Prompt user and take inputs
    printf("enter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    //Prompt user for matrix data and loop over matrix indicies to input
    printf("input for matrix 1: \n");
    for(int i = 0; i < rows; i++){

        printf("data for matrix1[%d][0] to matrix1[%d][%d] ", i, i, columns - 1);
        for(int j = 0; j < columns; j++){

            scanf("%d", &matrix1[i][j]);

        }

    }

    //Prompt user for matrix data and loop over matrix indicies to input
    printf("input for matrix 2: \n");
    for(int i = 0; i < rows; i++){

        printf("data for matrix2[%d][0] to matrix2[%d][%d] ", i, i, columns - 1);
        for(int j = 0; j < columns; j++){

            scanf("%d", &matrix2[i][j]);

        } 

    }

    //Display matricies
    printf("\nprinting matrix 1:\n");
    displayMatrix(matrix1, rows, columns);
    printf("printing matrix 2:\n");
    displayMatrix(matrix2, rows, columns);

    //Find and display max per row
    printf("\nprinting max per row for matrix 1:\n");
    findMaxPerRow(matrix1, rows, columns);

    //Display lower left leaning triangle of matrix one
    printf("\nprinting lower left triangle of matrix 1:\n");
    printLLTriangle(matrix1, rows, columns);

    //Display upper right leaning triangle of matrix two
    printf("\nprinting upper right triangle for matrix 1:\n");
    printURTriangle(matrix1, rows, columns);

    //Add and display the matricies
    addMatrix(matrix1, matrix2, results, rows, columns);
    printf("\nmatrix 1 + matrix 2 is:\n");
    displayMatrix(results, rows, columns);

    //Sum Surroundings
    while(1){
        printf("enter i and j for calculating sum of surrounding: ");
        scanf("%d %d", &rowInput, &columnInput);
        int sum = sumSurrounding(matrix1,rows, columns, rowInput, columnInput);
        if(rowInput < 0 || columnInput < 0){
            printf("Exit");
            break;
        }else{
            printf("sum of surrounding is %d\n", sum);
        }
    }


    return 0;
}

void displayMatrix(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols){
    //Use nested loop to display every row columns pair
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void findMaxPerRow(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols){

    //Ues nested for loop to check for max of every row
    for(int i = 0; i < rows; i++){
        //Define max at start of every row
        int max = matrix[i][0];
        for(int j = 0; j < cols; j++){
            //Check if any of the columns in that row are greater if so replace max with that column
            if(matrix[i][j]>max){
                max = matrix[i][j];
            }
        }

        //Print each row's max
        printf("max of row %d is %d\n", i, max);
    }
}

void printURTriangle(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols){

    //Use nested for loop to print right upper triangle
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            //If the column number is greater then or equal to the row then print the value else print 0
            if(j >= i){
                printf("%d ", matrix[i][j]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printLLTriangle(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols){
    //Use nested for loop to print left lower triangle
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            //If the column number is less then or equal to the row then print the value else print 0
            if(j <= i){
                printf("%d ", matrix[i][j]);
            }else{
                printf("0 ");
            }
        }
        printf("\n"); 
    }
}

void addMatrix(int matrix1[MAXROWS][MAXCOLUMNS],
               int matrix2[MAXROWS][MAXCOLUMNS],
               int result[MAXROWS][MAXCOLUMNS],
               int rows, int cols){
    //Iterate over every index of the matricies and add those values together
    //Set result equal to the results matrix at that index
    for( int i = 0; i < rows; i++){
        for( int j =0; j < cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
               }
int sumSurrounding(int matrix[MAXROWS][MAXCOLUMNS], int rows, int cols, int i, int j){
    int sum = 0;
    for(int r = i-1; r <= i + 1; r++){
        for(int c = j-1; c <= j+1 ; c++){
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                if (!(r == i && c == j)) {
                    sum += matrix[r][c];
                }
            }
        }
    }
    return sum;
}