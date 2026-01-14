#include <stdio.h>
#define MAX_SIZE 50000

void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void display_array(int arr[], int size);

int main() {
    int amount;
    int arr[MAX_SIZE];

    
    printf("How many numbers to sort?\n");
    scanf("%d", &amount);

    int copy1arr[MAX_SIZE];

    for (int i = 0; i < amount; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        copy1arr[i]=arr[i];
    }

    printf("Array before sorting:\n");
    for (int k = 0; k < amount; k++) {
        printf("%d ", arr[k]);
    }

    printf("\n");

    printf("\nUsing Bubble sort\n\n");
    bubble_sort(copy1arr,amount);

    printf("\nSorted array using Bubble Sort:\n");
    display_array(copy1arr,amount);

    printf("\n");

    printf("\nUsing Selection sort\n\n");
    selection_sort(arr, amount);
    
    printf("\nSorted array using Selection Sort::\n");
    display_array(arr,amount);
    

    return 0;
}

void display_array(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("Iteration# %d\n", i + 1);
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            display_array(arr, size);
        }
    }

}
void selection_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        
        printf("Iteration %d:\n", i + 1);
        display_array(arr,size);
        printf("\n");
    }
}
