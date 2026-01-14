// Online C compiler to run C program online
#include <stdio.h>
#define ROWS 10
#define COLUMNS 10

void FillData(int arr[ROWS][COLUMNS], int rows, int cols);
void Display(int arr[ROWS][COLUMNS], int rows, int cols);
void multiply(int arr1[ROWS][COLUMNS], int arr2[ROWS][COLUMNS], int rows1, int cols1, int rows2, int cols2);

int main() {
    
    int matrix1[ROWS][COLUMNS], matrix2[ROWS][COLUMNS];
    int rows1, columns1, rows2, columns2;
    
    printf("Working for Matrix 1\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows1,&columns1);
    FillData(matrix1, rows1, columns1);
    printf("Working for Matrix 2\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows2,&columns2);
    FillData(matrix2, rows2, columns2);
    printf("Displaying Matrix 1:\n");
    Display(matrix1, rows1, columns1);
    printf("Displaying Matrix 2:\n");
    Display(matrix2, rows2, columns2);
    printf("Displaying Result Matrix:\n");
    multiply(matrix1, matrix2,rows1,columns1,rows2,columns2);
    
    
    return 0;
}

void FillData(int arr[ROWS][COLUMNS], int rows, int cols){
    printf("Enter data for %dx%d matrix:\n", rows, cols);
    for(int i = 0; i < rows;i++){
        for(int j =0; j < cols; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

void Display(int arr[ROWS][COLUMNS], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void multiply(int arr1[ROWS][COLUMNS], int arr2[ROWS][COLUMNS], int rows1, int cols1, int rows2, int cols2){
    
    if (cols1 != rows2) {
        printf("Not valid dimensions for multiplication\n");
        return; // Exit the function if dimensions are invalid
    }
    
    int result[ROWS][COLUMNS] = {0};
    
    
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols2; j++){
            for(int k = 0; k < cols1; k++){
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols2; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}